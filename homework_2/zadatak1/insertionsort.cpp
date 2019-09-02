#include<iostream>
#include<chrono>
#include<thread>

void print(int* array, int n) {
  for (int i = 0; i < n; i++)
    std::cout << array[i] << ' ';
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  std::cout << "\r" ;
  std::flush(std::cout);
}

void insertion_sort(int* array, int n) {
  print(array,n);
  for (int i = 1; i < n; ++i) {
    for (int j = i; j != 0 && array[j] < array[j-1]; --j) {
      std::swap(array[j], array[j-1]);
      print(array, n);
    }
  }
}

int main(int argc, char *argv[])
{
  int a[] = {7,18,52,20,22,46,51,17,88};
  insertion_sort(a,9);
  for (const auto& i : a) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
