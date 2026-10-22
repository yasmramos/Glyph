#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "ast/Ast.h"

namespace glyph::parser {

/// Thrown when the source text cannot be parsed. Carries line/column so the
/// driver can print a precise diagnostic instead of a blind assert.
class ParseError : public std::runtime_error {
public:
    ParseError(const SourceLoc &loc, const std::string &message)
        : std::runtime_error(format(loc, message)), loc_(loc) {}

    const SourceLoc &loc() const { return loc_; }

private:
    static std::string format(const SourceLoc &loc, const std::string &message) {
        return loc.file + ":" + std::to_string(loc.line) + ":" +
               std::to_string(loc.col) + ": error: " + message;
    }

    SourceLoc loc_;
};

/// Parses Glyph source text into the language's own AST.
/// The returned Program is guaranteed non-null or a ParseError is thrown
/// (never a silent nullptr that would break later any_cast-style flows).
std::unique_ptr<ast::Program> parseSource(const std::string &text,
                                          const std::string &fileName);

} // namespace glyph::parser
