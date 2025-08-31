#pragma once

#include <string>

namespace oss {

// Returns a canonical "answer" for demo purposes.
int answer();

// Simple greeting utility to show a public API surface.
std::string greet(const std::string& name);

}  // namespace oss
