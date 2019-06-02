#include<iostream>

int odeprod(int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return n * odeprod(n-1);
  }
  return odeprod(n-1);
}

int main(int argc, char *argv[])
{
  std::cout << odeprod(6) << std::endl;
  return 0;
}
