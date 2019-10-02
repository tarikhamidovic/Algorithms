#include <iostream>

void binary_second(int one, int zero, std::string s, int l) {
  if (l == s.size()) {
    std::cout << s << std::endl;
    return;
  }
  binary_second(one + 1, zero, s + "1", l);
  if (one > zero)
    binary_second(one, zero + 1, s + "0", l);
}

void binary(int n) {
  binary_second(0, 0, "", n);
}

int main(int argc, char *argv[])
{
  while (true) {
    std::cout << "Unesite broj: ";
    int x;
    std::cin >> x;
    binary(x);
  }
  return 0;
}
