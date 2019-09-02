#include <iostream>

int pronadjiNajmanji(int* array, int n) {
  int mid = (n-1) / 2;
  if (n == 1)
    return *array;
  int min1 = pronadjiNajmanji(array, mid + 1);
  int min2 = pronadjiNajmanji(array + mid + 1, mid + 1);
  if (min1 < min2) {
    return min1;
  }
  else {
    return min2;
  }
}

int main(int argc, char *argv[])
{
  int A[] = {45,-425,545,55,2,1,-44,67};
  std::cout << "Najmanji je: "<< pronadjiNajmanji(A,8) << std::endl;
  return 0;
}
