#include <oss/starter/lib.hpp>
#include <iostream>

int main() {
  std::cout << "answer: " << oss::answer() << "\n";
  std::cout << oss::greet("world") << "\n";
  return 0;
}
