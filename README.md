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
