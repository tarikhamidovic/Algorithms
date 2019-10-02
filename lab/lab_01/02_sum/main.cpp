#include <iostream>
#include <chrono>

// implement a recursive function that adds two numbers
// suppose your computer only know how to increment or decrement a number
int sum(int n, int a) {
  if (n == 0) return a;
  return sum(n - 1, a + 1);
}

int main() {
  // std::cout << "5 + 3 = " << sum(5, 3) << std::endl;
  // std::cout << "10 + 100 = " << sum(10, 100) << std::endl;

  // auto now = std::chrono::steady_clock::now();
  // auto r = sum(100, 10);
  // auto elapsed = std::chrono::steady_clock::now() - now;
  // std::cout << "Computed 100 + 10 = " << r << std::endl;
  // std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
