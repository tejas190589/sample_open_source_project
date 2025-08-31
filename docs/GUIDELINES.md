# Coding Guidelines Summary

This codebase follows three pillars:

1. **MISRA C++ Mindset**
   - Deterministic behavior; no hidden control flow surprises
   - Prefer static memory; restrict dynamic allocation
   - Narrow interfaces; avoid globals; encapsulate state

2. **ISO C++ Core Guidelines**
   - *Type safety*: use RAII, `gsl::span`-style views over raw pointers
   - *Resource safety*: no naked `new/delete`; use smart pointers where needed
   - *Bounds safety*: avoid pointer arithmetic; prefer ranges/algorithms
   - *Const correctness*: make interfaces `const` where possible

3. **Clean Code**
   - Small functions, single responsibility
   - Clear names; avoid abbreviations
   - Tests document behavior
   - Comments explain *why*, not *what*

## Enforcement Map

| Theme | Primary Tooling | Examples |
|---|---|---|
| RAII / no leaks | clang-tidy `cppcoreguidelines-*`, sanitizer builds | avoid raw `new` |
| API clarity | review + clang-tidy readability rules | short headers, small interfaces |
| Bounds | static analysis + tests | use standard algorithms |
| No exceptions (opt) | `OSS_ENFORCE_NO_EXCEPTIONS=ON` | build flag |
| No RTTI (opt) | `OSS_ENFORCE_NO_RTTI=ON` | build flag |
| No dynamic alloc (opt) | `OSS_FORBID_DYNAMIC_ALLOCATION=ON` | link guard |

