#include <iostream>
#include <vector>

int func_r(int n) {
  if (n <= 2)
    return 1;
  if (n == 3)
    return 2;
  return func_r(n-1) + func_r(n-3) + func_r(n-4);
}

int func_mem(int n) {
  static std::vector<int> F(9999);
  if (n <= 2)
    return 1;
  if (n == 3)
    return 2;
  if (F[n] == 0)
    F[n] = func_mem(n-1) + func_mem(n-3) + func_mem(n-4);
  return F[n];
}

int func_dyn(int n) {
  if (n <= 2) 
    return 1;
  if (n == 3) 
    return 2;
  int a0 = 1;
  int a1 = 1;
  int a2 = 1;
  int a3 = 2;
  for (int i = 4; i <= n; i++) {
    auto temp = a3;
    a3 = a3 + a1 + a0;
    a0 = a1;
    a1 = a2;
    a2 = temp;
  }
  return a3;
}

int main(int argc, char *argv[])
{
  std::cout << func_r(5) << std::endl;
  std::cout << func_mem(5) << std::endl;
  std::cout << func_dyn(5) << std::endl;
  return 0;
}
