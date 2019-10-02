#include <iostream>
#include <chrono>

// implement a recursive function that computes the n-th fibonacci number
int fibonacci(int n) {
  if (n < 2) return 1;
  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
  std::cout << "Fibonacci of 1 is: " << fibonacci(1) << std::endl;
  std::cout << "Fibonacci of 2 is: " << fibonacci(2) << std::endl;
  std::cout << "Fibonacci of 3 is: " << fibonacci(3) << std::endl;
  std::cout << "Fibonacci of 4 is: " << fibonacci(4) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = fibonacci(20);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Fibonacci of 20 is: " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
