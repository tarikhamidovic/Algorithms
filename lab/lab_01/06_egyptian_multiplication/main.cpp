#include <iostream>
#include <chrono>

// implement a recursive function that computes the product of two
// numbers using the "Egyptian multiplication" method

int multiply(int n, int a) {
  if (n == 1) return a;
  return a + multiply(n - 1, a);
}

bool odd(int n) {
  return n & 1;
}

int half(int n) {
  return n >> 1;
}

int multiply1(int n, int a) {
  if (n == 1) return a;
  int result = 0;
  if (odd(a)) result = a;
  return multiply(half(n), a + a);
}

int main() {
  std::cout << "multiply 5 * 5 is: " << multiply(5, 5) << std::endl;
  std::cout << "multiply 5 * 11 is: " << multiply(5, 11) << std::endl;

  {
    auto now = std::chrono::steady_clock::now();
    auto r = multiply(1000, 55);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(100, 55) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }

  {
    auto now = std::chrono::steady_clock::now();
    auto r = multiply1(1000, 55);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(100, 55) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }
}
