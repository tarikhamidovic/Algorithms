#include<iostream>

int divide(int a, int b) {
  if (a < b) {
    return 0;
  }
  return divide(a-b, b) + 1;
}

int main(int argc, char *argv[])
{
  std::cout << divide(1,6) << std::endl;
  return 0;
}
