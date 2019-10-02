#include <iostream>
#include <string>
#include <vector>

int fibonacci_r(int n) {
  if (n < 2) {
    return n;
  }
  int last = fibonacci_r(n - 1);
  int  secondlast = fibonacci_r(n - 2);
  return last + secondlast;
}

int fibonacci_mem_impl(int n, std::vector<int>& mem_table) {
  if (mem_table[n] != 0)
    return mem_table[n];

  if (n < 2) {
    mem_table[n] = n;
    return mem_table[n];
  } else {
    int last = fibonacci_mem_impl(n - 1, mem_table);
    int  secondlast = fibonacci_mem_impl(n - 2, mem_table);
    mem_table[n] = last + secondlast;
    return mem_table[n];
  }
}

int fibonacci_mem(int n) {
  std::vector<int> mem_table;
  mem_table.resize(n);
  return fibonacci_mem_impl(n, mem_table);
};

int fibonacci_dyn(int n) {
  if (n < 2) return n;
  int last = 1;
  int secondlast = 0;
  for (int i = 1; i < n; i++) {
    int temp = secondlast;
    secondlast = last;
    last += temp;
  }
  return last;
}

int main() {
  int n = 8;
  std::cout << fibonacci_r(n) << std::endl;
  std::cout << fibonacci_mem(n) << std::endl;
  std::cout << fibonacci_dyn(n) << std::endl;
}
