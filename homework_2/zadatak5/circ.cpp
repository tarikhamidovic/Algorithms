#include<iostream>

int findMinCirc(int* array, int l, int r) {
  if (r < l)
    return array[0];
  if (l == r)
    return array[l];
  int mid = l + (r - l) / 2;
  if (mid < r && array[mid + 1] < array[mid])
    return array[mid + 1];
  if (mid > l && array[mid] < array[mid - 1])
    return array[mid];
  if (array[r] > array[mid])
    return findMinCirc(array, l, mid - 1);
  return findMinCirc(array, mid + 1, r);
}

int main(int argc, char *argv[])
{
  int A[] = {3,4,5,6,1,2};
  std::cout << "Najmanji je: " << findMinCirc(A,0,5) << std::endl;
  return 0;
}
