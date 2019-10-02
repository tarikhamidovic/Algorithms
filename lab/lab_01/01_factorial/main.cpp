#include <iostream>
#include <chrono>

// implement a recursive function that computes the factorial of a given number
int factorial(int n) {
  if (n < 1) return 1;
  return n * factorial(n - 1);
}

int main() {
  std::cout << "Factorial of 1 is: " << factorial(1) << std::endl;
  std::cout << "Factorial of 5 is: " << factorial(5) << std::endl;
  std::cout << "Factorial of 10 is: " << factorial(10) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = factorial(100);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Computed factorial(100) = " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
