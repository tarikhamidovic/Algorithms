#include <iostream>
#include <chrono>
#include <cmath>

double power(double a, int n);
// implement a general function that computes the n-th fibonacci number
// using the general case formula 
double fibonacci(int n) {
  const double root5 = std::sqrt(5.0);
  const double  c1 = (1 + root5) / 2;
  const double  c2 = (1 - root5) / 2;

  // double result = (1 / root5) * (power(c1, n) - power(c2, n));
  // return std::round(result);
  
  return 0;
}

double power(double a, int n) {
  return 0;
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

