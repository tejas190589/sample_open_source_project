#include <oss/starter/lib.hpp>
#include <cassert>
#include <string>

int main() {
  // Library returns 42
  assert(oss::answer() == 42);

  // Greeting contains the name
  std::string g = oss::greet("Tejas");
  assert(g.find("Tejas") != std::string::npos);
  return 0;
}
