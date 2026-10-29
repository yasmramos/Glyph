#pragma once

#include <string>

namespace glyph {

/// Location of a language construct in the source text.
/// Every AST node carries one so diagnostics can point at the right place.
struct SourceLoc {
    std::string file;
    int line = 0;
    int col = 0;
};

} // namespace glyph
