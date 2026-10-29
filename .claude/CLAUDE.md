# Project Instructions

## Language (mandatory)

- Write all source code identifiers in **English**.
- Write all code comments in **English**.
- Write all documentation (README, guides, API docs, commit messages, PR
  descriptions) in **English**.

## Git conventions

- Identity: `user.name = yasmramos`, `user.email = yasmramos95@gmail.com`.
- Remote: `origin` -> `https://github.com/yasmramos/Glyph.git` (HTTPS, token
  supplied through the local credential store, never embedded in tracked files
  or in `.git/config`).
- Work on the `develop` branch; create feature branches from it as
  `feat/<short-description>` and merge them back into `develop`.

### Commit messages: Conventional Commits, always in English

```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

Allowed types: `feat`, `fix`, `docs`, `style`, `refactor`, `perf`, `test`,
`build`, `ci`, `chore`, `revert`.

Rules: imperative mood ("add", not "added"), description not capitalized, no
trailing period, subject <= 72 characters.
