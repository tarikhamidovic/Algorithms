#include <iostream>
#include <chrono>

// implement a iterative fibonacci and measure its performance
unsigned long fibonacci(unsigned long n) {
  unsigned long n0 = 0;
  unsigned long n1 = 1;
  for (unsigned long i = 1; i < n; i ++) {
    auto temp = n1;
    n1 = n1 + n0;
    n0 = temp;
  }
  return n1;
}

int main() {
  std::cout << "Fibonacci of 1 is: " << fibonacci(1) << std::endl;
  std::cout << "Fibonacci of 2 is: " << fibonacci(2) << std::endl;
  std::cout << "Fibonacci of 3 is: " << fibonacci(3) << std::endl;
  std::cout << "Fibonacci of 4 is: " << fibonacci(4) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = fibonacci(50);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Fibonacci of 50 is: " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
