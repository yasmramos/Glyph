#!/usr/bin/env bash
# Generate the C++ parser/lexer/visitor sources from the ANTLR4 grammar.
# Usage: scripts/gen-parser.sh
set -euo pipefail

ANTLR_VERSION="4.13.1"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"
JAR="${ANTLR_JAR:-$ROOT_DIR/third_party/antlr-${ANTLR_VERSION}-complete.jar}"
GRAMMAR="$ROOT_DIR/grammars/Glyph.g4"
OUT_DIR="$ROOT_DIR/src/generated"

if [[ ! -f "$JAR" ]]; then
    echo "error: ANTLR jar not found at $JAR" >&2
    echo "download it with:" >&2
    echo "  mkdir -p third_party && curl -L -o $JAR https://www.antlr.org/download/antlr-${ANTLR_VERSION}-complete.jar" >&2
    exit 1
fi

rm -rf "$OUT_DIR"
mkdir -p "$OUT_DIR"

java -jar "$JAR" -Dlanguage=Cpp -visitor -no-listener -o "$OUT_DIR" "$GRAMMAR"

echo "generated sources in $OUT_DIR"
