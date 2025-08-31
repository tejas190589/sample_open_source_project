# Contributing

Thanks for your interest!

## Getting started

1. Fork and clone the repo.
2. Install a recent CMake and a C++17 compiler.
3. Configure and build:
   ```bash
   cmake -S . -B build -DBUILD_TESTING=ON
   cmake --build build
   ctest --test-dir build
   ```

## Coding standards

- C++17 (or higher)
- Follow `.clang-format` and `.editorconfig`
- Prefer small, focused PRs with tests and docs updated

## Commit messages

- Use concise, imperative moods (e.g., "Add X", "Fix Y").
- Reference issues like `Fixes #42` when applicable.

## Pull requests

- Run CI locally if possible
- Add/adjust tests
- Update `CHANGELOG.md` in the "Unreleased" section
- Ensure documentation builds

## Reporting security issues

Please do **not** file public issues. See [SECURITY.md](SECURITY.md).
