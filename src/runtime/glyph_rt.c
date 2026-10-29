/* Glyph runtime: minimal support library linked into compiled programs.
 * Kept in plain C; the header exposes it to C++ through extern "C".
 * No GC yet (documented policy): Glyph values at this stage are plain
 * doubles and string literals, so nothing here allocates. */
#include "glyph_rt.h"

#include <stdio.h>

/* Print a number the way Glyph shows it: integral values without a
 * trailing ".0", fractional values with enough precision to round-trip. */
void glyph_print_num(double value) {
    if (value == (long long)value && value > -1e15 && value < 1e15) {
        printf("%lld", (long long)value);
    } else {
        printf("%.14g", value);
    }
}

void glyph_print_str(const char *value) {
    fputs(value, stdout);
}

void glyph_print_nl(void) {
    putchar('\n');
    fflush(stdout);
}
