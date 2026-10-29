#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "ast/Ast.h"

namespace llvm {
class LLVMContext;
class Module;
} // namespace llvm

namespace glyph::codegen {

/// Thrown when code generation fails. Carries the source location of the
/// offending AST node so errors point at real positions (no blind asserts).
class CodeGenError : public std::runtime_error {
public:
    CodeGenError(const SourceLoc &loc, const std::string &message)
        : std::runtime_error(format(loc, message)), loc_(loc) {}

    const SourceLoc &loc() const { return loc_; }

private:
    static std::string format(const SourceLoc &loc, const std::string &msg) {
        return loc.file + ":" + std::to_string(loc.line) + ":" +
               std::to_string(loc.col) + ": error: " + msg;
    }

    SourceLoc loc_;
};

/// Generates an LLVM module from a Glyph AST.
/// Ownership order matters and is enforced by the caller:
/// LLVMContext outlives the Module, which outlives every llvm::Value*.
std::unique_ptr<llvm::Module> generateModule(const ast::Program &program,
                                             llvm::LLVMContext &ctx,
                                             const std::string &moduleName);

} // namespace glyph::codegen
