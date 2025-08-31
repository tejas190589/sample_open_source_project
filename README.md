# oss-starter

A minimal, modern C++ library template using CMake, CTest, and GitHub Actions.
Ready for open source: license, security policy, contribution guide, code of conduct, issue/PR templates, and docs.

## Quick start

```bash
git clone <your-fork-url> mylib
cd mylib
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

## Features

- CMake project with a library target `oss::starter`
- Header in `include/`, sources in `src/`, examples in `examples/`
- Tests with CTest (no external dependency)
- Install rules + export targets
- GitHub Actions CI (Linux/macOS/Windows)
- `.clang-format`, `.editorconfig`, `.gitignore`
- CONTRIBUTING, CODE_OF_CONDUCT, SECURITY, CHANGELOG
- Issue/PR templates
- Basic docs + ADR template

## Using the library

```cpp
#include <oss/starter/lib.hpp>
#include <iostream>

int main() {
    std::cout << oss::answer() << "\n";
}
```

## Build options

- `BUILD_TESTING` (ON/OFF): Enable tests (default ON if CTest is found).
- `OSS_WARNINGS_AS_ERRORS` (ON/OFF): Treat warnings as errors in this project (default OFF).

## License

MIT — see [LICENSE](LICENSE).


---

## MISRA C++ + Core Guidelines + Clean Code

This template ships with:

- **clang-tidy** (`.clang-tidy`) using `cppcoreguidelines`, `hicpp`, `bugprone`, `modernize`, `readability`, `performance`
- **cppcheck** config (`cppcheck.cfg`)
- **Pre-commit** hooks for formatting and linting (`.pre-commit-config.yaml`)
- **Compliance process** docs (`docs/MISRA_COMPLIANCE.md`) with RDP template and a CSV matrix

### Typical "strict" build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release   -DOSS_ENABLE_CLANG_TIDY=ON -DOSS_ENABLE_CPPCHECK=ON   -DOSS_ENFORCE_NO_EXCEPTIONS=ON -DOSS_ENFORCE_NO_RTTI=ON   -DOSS_FORBID_DYNAMIC_ALLOCATION=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

> Note: Full MISRA rule texts are copyrighted; this starter focuses on a *process* and *tooling* approach.
