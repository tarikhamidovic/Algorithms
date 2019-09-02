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

void quicksort(int* bg, int n) {
  if (n <= 1) return;
  int pivot_index = n / 2;
  std::swap(bg[pivot_index], bg[n - 1]);

  int left = -1;
  int right = n - 1;
  do {
  	while (bg[++left] < bg[n-1]);
  	while ((left < right) && bg[n-1] < bg[--right]);
  	std::swap(bg[left], bg[right]);
  } while (left < right);
  std::swap(bg[left], bg[n - 1]);

  print(bg, n);
  quicksort(bg, left);
  print(bg,n);
  quicksort(bg + left + 1, n - left - 1);
  print(bg,n);
}

int main(int argc, char *argv[])
{
  int a[] = {7,18,52,20,22,46,51,17,88};
  quicksort(a,9);
  for (const auto& i : a) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
