# Glyph Language Specification (Draft 0.1)

This document defines the design of **Glyph**, a small statically-scoped,
dynamically-typed scripting language compiled through LLVM (version 23).
All language documentation is written in English.

- Status: draft, milestone 3 implemented; milestones 4–6 planned.
- Grammar source of truth: `grammars/Glyph.g4` (ANTLR 4).
- Implementation pipeline: ANTLR parse tree → own AST (`src/ast`) → LLVM IR
  (`src/codegen`) → native object file / executable.

---

## 1. Design Goals

1. **Minimal but familiar syntax** — Lua-inspired statements and operators,
   with a Python-like feel for control flow.
2. **Ahead-of-time compilation** — every program compiles to native code via
   LLVM 23; there is no interpreter loop in the final product.
3. **Dynamic values first** — the core runtime value is a tagged union
   (`Value`) so scripts stay lightweight; a static mode may come later.
4. **Predictable scoping** — lexical scoping rules that are easy to reason
   about (Lua-style `local`).
5. **Small C runtime** — GC-optional, reference-counted or arena-managed
   memory (open question, see §10).

Non-goals for now: concurrency, metaprogramming, a module/package system.

## 2. Lexical Structure

### 2.1 Program text
- Source files use the extension `.glyph`.
- Encoding: UTF-8. Identifiers are ASCII-only for now.
- Newlines are not significant tokens (unlike Lua); statements are delimited
  by their keywords or by newlines implicitly at the parser level.

### 2.2 Comments
```glyph
-- line comment runs to end of line
--[[ block comment
     can span lines ]]
```

### 2.3 Keywords (reserved)
Current: `print`, `local`, `and`, `or`, `not`.
Planned: `if`, `else`, `elseif`, `end`, `while`, `do`, `for`, `in`, `fun`,
`return`, `true`, `false`, `nil`.

### 2.4 Identifiers
`[a-zA-Z_][a-zA-Z0-9_]*`

### 2.5 Number literals
- Integer: `42`
- Fractional: `3.14` (digits required on both sides of the dot)
- Internally every number is an IEEE-754 double (`num` type).

### 2.6 String literals
- Delimited by `"` or `'`; both forms are equivalent.
- Escape sequences: `\n \t \\ \" \'` (full table in §5.2).
- No interpolation yet (planned: `"{expr}"` string templates).

## 3. Types

### 3.1 Dynamic value model (milestones 1–3, current)
| Type   | Literal examples        | Notes                          |
|--------|-------------------------|--------------------------------|
| `num`  | `1`, `2.5`              | always `double`                |
| `str`  | `"hi"`, `'hi'`          | immutable byte strings         |
| `bool` | `true`, `false` (soon)  | currently derived from ops     |
| `nil`  | `nil` (planned)         | absence of value               |

### 3.2 Static type annotations (planned, milestone 4+)
Optional annotations `x: num = 1` checked by a semantic pass before codegen.
The compiler will infer types where possible; annotations document intent
and enable better diagnostics.

## 4. Operators and Precedence

From lowest to highest precedence (as encoded in `Glyph.g4`):

| Level | Operators        | Associativity |
|-------|------------------|---------------|
| 1     | `or`             | left          |
| 2     | `and`            | left          |
| 3     | `==` `~=`        | non-assoc     |
| 4     | `<` `<=` `>` `>=`| non-assoc     |
| 5     | `+` `-`          | left          |
| 6     | `*` `/` `%`      | left          |
| 7     | `^`              | **right**     |
| 8     | unary `-`, `not` | prefix        |
| 9     | primary (literals, `(...)`, identifiers) | — |

Notes:
- `~=` is inequality (Lua heritage). Consider aliasing `!=` (open question).
- `%` is floating-point remainder (`fmod`) for now; integer semantics may be
  introduced with a dedicated `int` type.
- Mixed `num`/`str` arithmetic raises a compile-time error when detectable,
  otherwise a runtime error (§5.3).

## 5. Semantics

### 5.1 Variables and scope
- Assignment creates or updates a variable. Without `local`, assignment
  targets the nearest enclosing scope that already declares the name,
  else the global scope (Lua rule).
- `local x = e` always declares a fresh variable in the current block scope.
- Reading an undeclared variable is a **compile-time error**
  (already enforced: see test `error_undefined_var.glyph`).

### 5.2 Strings
- Immutable. Comparisons `==`/`~=` compare contents.
- Escapes processed at lexing time into raw bytes.

### 5.3 Errors
- Syntax errors: reported by ANTLR with file:line:col.
- Semantic errors (undefined variable, arity mismatch): reported by the
  AstBuilder/type pass before codegen.
- Type mismatches that cannot be detected statically are currently rejected
  at compile time by CodeGen (`CodeGenError`, e.g. "cannot negate a string").
  A dynamic `Value` model with a runtime error path is planned for
  milestone 4+ (see §3.2 and open questions).

### 5.4 Output
`print(e)` writes one value per call followed by a newline (stdout is
flushed after each statement). Numbers render without a trailing `.0` when
integral (printed as `%lld`), otherwise with `%.14g`; strings print raw
(no quotes).

## 6. Control Flow (Planned — Milestone 4)

```glyph
if x > 10 then
    print("big")
elseif x > 0 then
    print("small positive")
else
    print("non positive")
end

while i < n do
    i = i + 1
end

-- Numeric for: from/to/step, bounds evaluated once, step defaults to 1
for i = 1, 10, 2 do
    print(i)
end
```

Design decisions:
- Block keyword `end` closes every compound statement (Lua-style), keeping
  the grammar unambiguous without indentation rules.
- Conditions use "truthiness": `nil` and `false` are falsy, everything else
  is truthy. Planned.

## 7. Functions (Planned — Milestone 5)

```glyph
fun add(a, b): num {
    return a + b
}

local twice = fun(x) { return x * 2 }   -- first-class lambdas
print(add(2, 3))
print(twice(21))
```

- `fun NAME(params) [: retType] { body }` declares a named function.
- Anonymous form `fun(params) { body }` yields a closure value.
- Multiple return values are **out of scope** for v0.1 (single `return expr`).
- Recursion supported; tail calls optional optimization later.
- Capture semantics: closures capture variables by reference (shared), like
  Lua upvalues.

## 8. Data Structures (Planned — Milestone 6)

Lightweight record/tuple syntax under consideration:

```glyph
local p = { x: 1, y: 2 }     -- record literal
local t = [1, 2, 3]          -- list literal
print(p.x)
print(t[0])
```

Decision pending: whether lists are homogeneous (static) or heterogeneous
(dynamic `Value` array). Current lean: dynamic `Value` array for v0.1.

## 9. Reserved Words and Future Extensions

Explicitly deferred: `break`, `continue`, `match`, `struct`, `enum`,
`import`, garbage-collection annotations, string interpolation, integer
types, `+=` compound assignment.

## 10. Open Questions

1. Inequality operator: keep `~=`, add `!=`, or switch to `!=`?
2. Should `%` become integer-modulo when both operands are integral doubles?
3. Truthiness of `0` and `""`: truthy (Lua) — confirm.
4. Statement terminator policy: implicit newline separation vs. optional `;`.
5. Module system shape (`import` vs. `include`) — post-v0.1.

## 11. Mapping to the Compiler Pipeline

| Spec section        | Implementation artifact                     |
|---------------------|---------------------------------------------|
| Lexical structure   | `grammars/Glyph.g4` lexer rules             |
| Grammar/precedence  | `grammars/Glyph.g4` parser rules            |
| AST                 | `src/ast/Ast.h`                             |
| Semantic checks     | `src/parser/AstBuilder.cpp`                 |
| Codegen (LLVM 23)   | `src/codegen/CodeGen.cpp`                   |
| Runtime semantics   | `src/runtime/glyph_rt.{h,c}`                |
| Acceptance tests    | `tests/cases/*.{glyph,expected}`            |

Any change to this specification must land together with:
grammar updates, regenerated parser, AST/codegen support, and at least one
test case under `tests/cases/`.
