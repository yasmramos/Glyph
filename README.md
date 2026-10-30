# Glyph

Glyph is a small compiled scripting language built on **LLVM 23**. Source
programs (`.glyph` files) are parsed with an ANTLR 4 grammar, lowered to a
dedicated AST, and compiled to native code through LLVM IR.

## Language design

The full specification lives in [`docs/LANGUAGE.md`](docs/LANGUAGE.md).
Highlights:

- **Dynamic value model** (`num`, `str`, planned `bool`/`nil`) with Lua-style
  lexical scoping (`local`).
- **Expression language** with Lua-inspired operators: `and` / `or` / `not`,
  `==` / `~=`, `< <= > >=`, `+ - * / %`, right-associative `^`.
- **Ahead-of-time compilation**: no interpreter; the output is a native
  executable linked against a tiny C runtime (`src/runtime`).
- **Planned**: control flow (`if` / `while` / `for`, milestone 4), functions
  and closures (`fun`, milestone 5), records and lists (milestone 6).

### Example

```glyph
local answer = 6 * 7
print("Hello from Glyph!")
print(answer)          -- 42
print(2 ^ 0.5)         -- 1.4142135623731
```

## Repository layout

| Path            | Contents                                        |
|-----------------|-------------------------------------------------|
| `docs/`         | Language specification and design notes         |
| `grammars/`     | ANTLR 4 grammar (`Glyph.g4`) — source of truth  |
| `src/ast/`      | Own AST types (no ANTLR/LLVM dependencies)      |
| `src/parser/`   | Parse-tree -> AST builder + semantic checks     |
| `src/codegen/`  | AST -> LLVM IR (LLVM 23)                        |
| `src/runtime/`  | Minimal C runtime linked into compiled programs |
| `tests/cases/`  | Acceptance tests (`.glyph` + `.expected`)       |
| `examples/`     | Sample programs                                 |

## Contributing

See [`CONTRIBUTING.md`](CONTRIBUTING.md): English-only code, comments and
documentation; Conventional Commits; work on `develop`. Any change to the
language must update `docs/LANGUAGE.md`, the grammar, and add a test case.
