# Contribution Guidelines

These conventions apply to all work done in this repository.

## Language

- All source code identifiers (variables, functions, classes) must be written in English.
- All code comments must be written in English.
- All documentation (README, guides, API docs) must be written in English.

## Commit Messages

Commits must follow the Conventional Commits specification, always in English:

```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

Allowed types:

- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation changes
- `style`: Formatting changes (no code logic change)
- `refactor`: Code refactoring
- `perf`: Performance improvements
- `test`: Adding or fixing tests
- `build`: Build system or dependency changes
- `ci`: CI configuration changes
- `chore`: Maintenance tasks
- `revert`: Reverting a commit

Rules:

- Use the imperative mood ("add" not "added").
- Do not capitalize the description.
- No trailing period in the subject line.

## Branching Model

- `main`: production-ready code only.
- `develop`: integration branch for ongoing development. Daily work happens here.
- Feature branches: created from `develop` using the naming convention `feat/<short-description>` (e.g., `feat/login-page`). Merge back into `develop`.
- Release branches are cut from `develop` into `main`, then `develop` is merged back.

## Git Configuration

Repository identity is configured globally as:

- `user.name = yasmramos`
- `user.email = yasmramos95@gmail.com`

The remote uses HTTPS with a personal access token embedded in the remote URL
(never commit real tokens into tracked files).
