#include<iostream>

int sum(int* array, int n) {
  if (n == 0) {
    return 0;
  }
  return *array + sum(array + 1, n - 1);
}

int main(int argc, char *argv[])
{
  int a[] = {1,2,3,4,5};
  std::cout << sum(a,5) << std::endl;
  return 0;
}
