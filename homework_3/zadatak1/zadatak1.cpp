#include <iostream>
#include <vector>

int sekvenca_r(int n) {
  if (n == 0)
    return 2;
  if (n == 1)
    return 4;
  if (n == 2)
    return 12;
  return 3*sekvenca_r(n-3) + 2*sekvenca_r(n-2) + sekvenca_r(n-3);
}

int sekvenca_mem(int n) {
  static std::vector<int> F(9999);
  if (n == 0)
    return 2;
  if (n == 1)
    return 4;
  if (n == 2)
    return 12;
  else {
    if (F[n] == 0)
      F[n] = 3*sekvenca_mem(n-3) + 2*sekvenca_mem(n-2) + sekvenca_mem(n-3);
    return F[n];
  }
}

int sekvenca_dyn(int n) {
  if (n == 0)
    return 2;
  if (n == 1)
    return 4;
  if (n == 2)
    return 12;
  int a0 = 2;
  int a1 = 4;
  int a2 = 12;
  for (int i = 3; i <= n; i++) {
    auto temp = a2;
    a2 = 3*a0 + 2*a1 + a0;
    a0 = a1;
    a1 = temp;
  }
  return a2;
}

int main(int argc, char *argv[])
{
  int x;
  while (true) {
    std::cout << "Unesite vrijednost: ";
    std::cin >> x;
    std::cout << "Rekurzivno: " << sekvenca_r(x) << std::endl;
    std::cout << "Memoizacija: " << sekvenca_mem(x) << std::endl;
    std::cout << "Dinamicko pro.: " << sekvenca_dyn(x) << std::endl;
  }
  return 0;
}
