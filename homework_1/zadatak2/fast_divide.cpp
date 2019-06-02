#include<iostream>

int greatestPowerOf2(int a, int b) {
  int power = 0;
  while (b <= a) {
    power++;
    b = b << 1;
  }
  return power - 1;
}

int fast_divide(int a, int n) {
  if (n == 0) {
    std::cout << "Dijelenje nulom nije definisano za cijele brojeve!" << std::endl;
    return -1;
  }
  auto greatest = greatestPowerOf2(a,n);
  if (a < n) {
    return 0;
  }
  if (a == (n << greatest)) {
    return 1 << greatest;
  }
  if (a > (n << greatest)) {
    return (1 << greatest) + fast_divide(a - (n << greatest), n);
  }
}

int main(int argc, char *argv[])
{
  std::cout << fast_divide(20,5) << std::endl;
  return 0;
}
