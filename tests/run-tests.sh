#!/usr/bin/env bash
# End-to-end test runner for glyphc (checklist §9).
# Pairs in tests/cases: <name>.glyph + <name>.expected for successful runs;
# error cases are listed explicitly with the expected exit code and a grep
# pattern for the diagnostic.
set -u

GLYPHC="${GLYPHC:-$(dirname "$0")/../build/glyphc}"
CASES="$(dirname "$0")/cases"
PASS=0
FAIL=0

fail() { echo "FAIL: $1"; FAIL=$((FAIL+1)); }
pass() { echo "ok:   $1"; PASS=$((PASS+1)); }

if [[ ! -x "$GLYPHC" ]]; then
    echo "error: glyphc not found at $GLYPHC" >&2
    exit 1
fi

# --- version smoke test (Hito 0) --------------------------------------------
if "$GLYPHC" --version | grep -q "glyphc"; then
    pass "--version"
else
    fail "--version"
fi

# --- golden output tests -----------------------------------------------------
for glyph_file in "$CASES"/milestone*.glyph; do
    name="$(basename "$glyph_file" .glyph)"
    expected="$CASES/$name.expected"
    actual="$(cd "$(dirname "$glyph_file")" && "$GLYPHC" run "$name.glyph" 2>&1)"
    want="$(cat "$expected")"
    if [[ "$actual" == "$want" ]]; then
        pass "$name"
    else
        fail "$name"
        echo "--- expected ---"; echo "$want"
        echo "--- actual   ---"; echo "$actual"
    fi
done

# --- IR sanity: verifyModule already runs inside glyphc; check emit-ir works.
if "$GLYPHC" build --emit-ir "$CASES/milestone1.glyph" | grep -q "glyph_print_num"; then
    pass "emit-ir contains runtime call"
else
    fail "emit-ir contains runtime call"
fi

# --- error tests -------------------------------------------------------------
check_error() { # name file expected_exit grep_pattern
    local out status
    out="$("$GLYPHC" build "$2" 2>&1)"; status=$?
    if [[ $status -ge 1 ]] && grep -q "$3" <<<"$out"; then
        pass "$1"
    else
        fail "$1 (exit=$status, out=$out)"
    fi
}
check_error "error_unterminated_string" "$CASES/error_unterminated_string.glyph" "error:"
check_error "error_missing_paren"       "$CASES/error_missing_paren.glyph"       "error:"
check_error "error_undefined_var"       "$CASES/error_undefined_var.glyph"       "undefined variable"

echo "----------------------------------------"
echo "passed: $PASS  failed: $FAIL"
[[ $FAIL -eq 0 ]]
