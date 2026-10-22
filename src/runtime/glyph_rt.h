#ifndef GLYPH_RT_H
#define GLYPH_RT_H

/* Pure C header: usable from glyph_rt.c (compiled as C) and from the C++
 * driver through the extern "C" block below. The whole project uses
 * #pragma once in C++ headers; this file is the deliberate exception
 * because it must also compile under a plain C toolchain. */

#ifdef __cplusplus
extern "C" {
#endif

/* The Glyph runtime is a tiny C library (glyph_rt.c) linked into every
 * compiled program and also loaded in-process for the JIT/REPL.
 * All symbols use extern "C" to avoid name mangling.
 *
 * Value representation (early design decision, see docs/architecture.md):
 * numbers are `double`, strings are NUL-terminated `const char*`.
 * print is split per type: glyph_print_num / glyph_print_str, plus
 * glyph_print_nl to terminate the line. */

void glyph_print_num(double value);
void glyph_print_str(const char *value);
void glyph_print_nl(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
#include <string>

namespace glyph::runtime {

/* Locates the runtime archive (libglyph_rt.a) built next to the compiler
 * binary so the driver can link it with `cc` (never raw `ld`: crt*.o and
 * libc come free with the compiler driver). Returns an empty string when
 * not found. */
std::string locateRuntimeObject();

} // namespace glyph::runtime
#endif

#endif /* GLYPH_RT_H */
