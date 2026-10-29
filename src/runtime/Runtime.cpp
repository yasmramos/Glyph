#include "runtime/glyph_rt.h"

#include <filesystem>

namespace glyph::runtime {

std::string locateRuntimeObject() {
    // The CMake build produces libglyph_rt.a in the build tree; look for it
    // relative to the executable being run. `cc` accepts static archives
    // directly (never raw `ld`: crt*.o and libc come free with cc).
    std::error_code ec;
    auto exeDir = std::filesystem::read_symlink("/proc/self/exe", ec).parent_path();
    if (!ec) {
        for (const auto &candidate :
             {exeDir / "libglyph_rt.a", exeDir / "runtime" / "libglyph_rt.a"}) {
            if (std::filesystem::exists(candidate)) {
                return candidate.string();
            }
        }
    }
    return {};
}

} // namespace glyph::runtime
