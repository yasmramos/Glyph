#include "runtime/glyph_rt.h"

#include <filesystem>

namespace glyph::runtime {

#ifdef _WIN32
#include <windows.h>

static std::string exeDirectory() {
    char buf[MAX_PATH];
    DWORD n = GetModuleFileNameA(nullptr, buf, sizeof(buf));
    if (n == 0 || n >= sizeof(buf)) return {};
    std::filesystem::path exe(buf);
    // read_symlink is not available on Windows; GetModuleFileName already
    // returns the resolved path of the running executable.
    return exe.parent_path().string();
}

#else

static std::string exeDirectory() {
    std::error_code ec;
    return std::filesystem::read_symlink("/proc/self/exe", ec)
        .parent_path()
        .string();
}
#endif

std::string locateRuntimeObject() {
    // The CMake build produces libglyph_rt.a (glyph_rt.lib on Windows) in
    // the build tree; look for it relative to the executable being run.
    // `cc`/`cl` accept static archives directly (never raw `ld`: crt*.o and
    // libc come free with the compiler driver).
    auto exeDir = std::filesystem::path(exeDirectory());
    if (exeDir.empty()) return {};
#ifdef _WIN32
    const char *names[] = {"glyph_rt.lib", "runtime\\glyph_rt.lib"};
#else
    const char *names[] = {"libglyph_rt.a", "runtime/libglyph_rt.a"};
#endif
    for (const auto *name : names) {
        auto candidate = exeDir / name;
        if (std::filesystem::exists(candidate)) {
            return candidate.string();
        }
    }
    return {};
}

} // namespace glyph::runtime
