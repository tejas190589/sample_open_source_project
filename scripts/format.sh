#!/usr/bin/env bash
set -euo pipefail
command -v clang-format >/dev/null 2>&1 || { echo "clang-format not found"; exit 1; }
find include src tests examples -name '*.[ch]pp' -o -name '*.h' -o -name '*.cxx' | xargs clang-format -i
echo "Formatted."
