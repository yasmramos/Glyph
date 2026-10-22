// glyphc — the Glyph compiler driver.
// Subcommands: build, run, repl (milestone 6+). Flags: -o, -O, --emit-ir,
// --emit-asm, --ast.
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "llvm/ADT/StringRef.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include "ast/Ast.h"
#include "codegen/CodeGen.h"
#include "parser/Parser.h"
#include "runtime/glyph_rt.h"

namespace {

const char *kVersion = "0.1.0";

struct Options {
    std::string input;
    std::string output;          // -o
    int optLevel = 0;            // -O0..-O3
    bool emitIR = false;         // --emit-ir
    bool emitAsm = false;        // --emit-asm
    bool dumpAst = false;        // --ast
    bool keepTemps = false;      // --keep-temps (debug)
};

void usage() {
    std::cerr <<
        "usage: glyphc <command> [options] <file.glyph>\n"
        "commands:\n"
        "  build          compile to an executable\n"
        "  run            compile and execute\n"
        "options:\n"
        "  -o <file>      output path (build)\n"
        "  -O0|-O1|-O2|-O3 optimization level (default -O0 for readable IR)\n"
        "  --emit-ir      print LLVM IR instead of compiling\n"
        "  --emit-asm     print assembly instead of compiling\n"
        "  --ast          print the AST instead of compiling\n"
        "  --keep-temps   keep intermediate .o files\n";
}

int spawn(const std::vector<std::string> &argv) {
    // fork/execvp instead of system(): no shell, so no injection surface.
    std::vector<char *> raw;
    raw.reserve(argv.size() + 1);
    for (auto &arg : argv) raw.push_back(const_cast<char *>(arg.c_str()));
    raw.push_back(nullptr);

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "glyphc: fork failed\n";
        return 1;
    }
    if (pid == 0) {
        execvp(raw[0], raw.data());
        _exit(127);
    }
    int status = 0;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) return WEXITSTATUS(status);
    return 1;
}

std::string readFile(const std::string &path) {
    std::ifstream in(path);
    if (!in) {
        throw glyph::parser::ParseError(glyph::SourceLoc{path, 0, 0},
                                        "cannot open input file");
    }
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

/// Runs the new pass manager pipeline on the module. verifyModule MUST run
/// first: PassBuilder on invalid IR is a segfault waiting to happen.
void optimizeModule(llvm::Module &module, int level) {
    using namespace llvm;
    if (level == 0) return; // Keep IR fully readable at -O0 for debugging.
    LoopAnalysisManager lam;
    FunctionAnalysisManager fam;
    CGSCCAnalysisManager cgam;
    ModuleAnalysisManager mam;

    PassBuilder pb;
    pb.registerModuleAnalyses(mam);
    pb.registerCGSCCAnalyses(cgam);
    pb.registerFunctionAnalyses(fam);
    pb.registerLoopAnalyses(lam);
    pb.crossRegisterProxies(lam, fam, cgam, mam);

    OptimizationLevel ol = level >= 3 ? OptimizationLevel::O3
                            : level == 2 ? OptimizationLevel::O2
                                         : OptimizationLevel::O1;
    auto mpm = pb.buildPerModuleDefaultPipeline(ol);
    mpm.run(module, mam);
}

/// Emits an object file through the native target backend.
bool emitObject(llvm::Module &module, const std::string &path) {
    using namespace llvm;
    std::string err;
    Triple triple(sys::getDefaultTargetTriple());
    auto *target = TargetRegistry::lookupTarget("", triple, err);
    if (!target) {
        std::cerr << "glyphc: no target for " << triple.str() << ": " << err
                  << "\n";
        return false;
    }
    TargetOptions options;
    std::unique_ptr<TargetMachine> tm(target->createTargetMachine(
        triple.str(), "generic", "", options, Reloc::PIC_));
    module.setDataLayout(tm->createDataLayout());
    module.setTargetTriple(triple);

    legacy::PassManager pm;
    std::error_code ec;
    raw_fd_ostream out(path, ec, sys::fs::OF_None);
    if (ec) {
        std::cerr << "glyphc: cannot write " << path << ": " << ec.message()
                  << "\n";
        return false;
    }
    // CGFT_ObjectFile gives us a .o; linking it needs cc, never raw ld.
    if (tm->addPassesToEmitFile(pm, out, nullptr, CGFT_ObjectFile)) {
        std::cerr << "glyphc: target cannot emit object files\n";
        return false;
    }
    pm.run(module);
    out.flush();
    return true;
}

int cmdCompile(const Options &opts, bool thenRun) {
    using namespace llvm;

    std::string text = readFile(opts.input);

    // Stage 1: parse into Glyph's own AST.
    std::unique_ptr<glyph::ast::Program> program;
    try {
        program = glyph::parser::parseSource(text, opts.input);
    } catch (const glyph::parser::ParseError &e) {
        llvm::errs() << e.what() << "\n";
        return 1;
    }

    if (opts.dumpAst) {
        glyph::ast::printAst(*program);
        return 0;
    }

    // Stage 2: LLVM IR. Construction order enforces Context > Module lifetime.
    LLVMContext ctx;
    std::unique_ptr<Module> module;
    try {
        module = glyph::codegen::generateModule(*program, ctx, opts.input);
    } catch (const glyph::codegen::CodeGenError &e) {
        llvm::errs() << e.what() << "\n";
        return 1;
    }

    // Verify before anything else touches the IR (optimizer or backend).
    std::string verifyErrs;
    raw_string_ostream verifyOut(verifyErrs);
    if (verifyModule(*module, &verifyOut)) {
        verifyOut.flush();
        llvm::errs() << "glyphc: internal codegen error, invalid IR:\n"
                     << verifyErrs;
        return 2;
    }

    optimizeModule(*module, opts.optLevel);

    if (opts.emitIR) {
        module->print(llvm::outs(), nullptr);
        return 0;
    }

    // Stage 3: object file + link with the system C compiler.
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    if (opts.emitAsm) {
        // Assembly goes through a temporary .s produced by CGFT_AssemblyFile.
        std::string tmp = opts.input + ".tmp.s";
        legacy::PassManager pm;
        std::error_code ec;
        raw_fd_ostream out(tmp, ec, sys::fs::OF_None);
        Triple triple(sys::getDefaultTargetTriple());
        std::string err;
        auto *target = TargetRegistry::lookupTarget("", triple, err);
        if (!target) { llvm::errs() << "glyphc: " << err << "\n"; return 2; }
        std::unique_ptr<TargetMachine> tm(target->createTargetMachine(
            triple.str(), "generic", "", TargetOptions{}, Reloc::PIC_));
        module->setDataLayout(tm->createDataLayout());
        if (tm->addPassesToEmitFile(pm, out, nullptr, CGFT_AssemblyFile)) {
            llvm::errs() << "glyphc: cannot emit asm\n";
            return 2;
        }
        pm.run(*module);
        out.flush();
        std::ifstream in(tmp);
        std::ostringstream ss;
        ss << in.rdbuf();
        llvm::outs() << ss.str();
        if (!opts.keepTemps) std::filesystem::remove(tmp);
        return 0;
    }

    std::string objPath = opts.output.empty()
                              ? (std::filesystem::temp_directory_path() /
                                 ("glyph-" +
                                  std::to_string(::getpid()) + ".o"))
                                    .string()
                              : opts.output + ".o";
    if (!emitObject(*module, objPath)) return 2;

    std::string exePath = opts.output.empty() ? "a.out" : opts.output;
    std::vector<std::string> cc = {"cc", objPath};
    if (auto rt = glyph::runtime::locateRuntimeObject(); !rt.empty()) {
        cc.push_back(rt);
    }
    cc.push_back("-o");
    cc.push_back(exePath);
    cc.push_back("-lm");
    int rc = spawn(cc);
    if (!opts.keepTemps && opts.output.empty()) {
        std::filesystem::remove(objPath);
    }
    if (rc != 0) {
        llvm::errs() << "glyphc: linker failed with status " << rc << "\n";
        return rc;
    }

    if (thenRun) {
        std::string self = ".";
        std::vector<std::string> run = {exePath};
        rc = spawn(run);
        if (!opts.keepTemps && opts.output.empty()) {
            std::filesystem::remove(exePath);
        }
        return rc;
    }
    return 0;
}

} // namespace

int main(int argc, char **argv) {
    std::vector<std::string> args(argv + 1, argv + argc);
    if (args.empty()) {
        usage();
        return 1;
    }

    if (args[0] == "--version") {
        std::cout << "glyphc " << kVersion << " (LLVM " << LLVM_VERSION_MAJOR
                  << ", ANTLR 4.13.1)\n";
        return 0;
    }

    std::string command = args[0];
    if (command != "build" && command != "run") {
        std::cerr << "glyphc: unknown command '" << command << "'\n";
        usage();
        return 1;
    }

    Options opts;
    for (size_t i = 1; i < args.size(); ++i) {
        const std::string &a = args[i];
        if (a == "-o" && i + 1 < args.size()) {
            opts.output = args[++i];
        } else if (a == "--emit-ir") {
            opts.emitIR = true;
        } else if (a == "--emit-asm") {
            opts.emitAsm = true;
        } else if (a == "--ast") {
            opts.dumpAst = true;
        } else if (a == "--keep-temps") {
            opts.keepTemps = true;
        } else if (a.size() >= 3 && a[0] == '-' && a[1] == 'O' &&
                   isdigit(static_cast<unsigned char>(a[2]))) {
            opts.optLevel = a[2] - '0';
        } else if (!a.empty() && a[0] != '-') {
            opts.input = a;
        } else {
            std::cerr << "glyphc: unknown option '" << a << "'\n";
            return 1;
        }
    }

    if (opts.input.empty()) {
        std::cerr << "glyphc: no input file\n";
        usage();
        return 1;
    }

    return cmdCompile(opts, /*thenRun=*/command == "run");
}
