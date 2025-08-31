# MISRA C++ Compliance (Process)

This project aims to be **MISRA C++-friendly** by process and tooling, while acknowledging that
full, audited compliance requires commercial rule sets and reviews.

## Principles

- Prefer static analysis and safe defaults
- Avoid dynamic allocation in production builds (configurable)
- Limit exceptions and RTTI (configurable)
- Enforce Core Guidelines/HIC++ checks via `clang-tidy`
- Track deviations with Rule Deviation Permits (RDPs)
- Keep interfaces simple, side‑effect free, and documented

## Tooling Strategy

- **clang-tidy**: `cppcoreguidelines-*`, `hicpp-*`, `bugprone-*`, `modernize-*`, etc.
- **cppcheck**: warnings/performance/portability with `--inconclusive`
- **Compiler flags**: treat warnings seriously; optional `-fno-exceptions`, `-fno-rtti`
- **Format**: `.clang-format` and `.editorconfig`

> Note: MISRA rule texts are not included (copyright). We track coverage via
a *compliance matrix* and deviations via RDPs.

## Deviations

When a rule must be broken, document it:

- Create an RDP in `docs/misra/rdp/RDP-<id>.md` using the template below.
- Reference the deviation in code with a clear one‑line comment including the RDP id.
- Add an entry in `docs/misra/misra_compliance_matrix.csv` with status `Deviated`.

See: `docs/misra/templates/RDP-TEMPLATE.md`.

## Build Modes

- `OSS_ENFORCE_NO_EXCEPTIONS=ON` → compiles with exceptions disabled where supported
- `OSS_ENFORCE_NO_RTTI=ON` → compiles with RTTI disabled where supported
- `OSS_FORBID_DYNAMIC_ALLOCATION=ON` → links a guard that deletes global `new/delete`

These options are intended for production configurations; tests/examples may relax them.

## Coverage Matrix

Track your project rules coverage in: `docs/misra/misra_compliance_matrix.csv`.
