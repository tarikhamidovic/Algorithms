#include<iostream>
#include<chrono>
#include<thread>

void print(int* array, int n) {
  for (int i = 0; i < n; i++)
    std::cout << array[i] << ' ';
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "\r" ;
  std::flush(std::cout);
}

void merge(int* array1, int array1len, int* array2, int array2len, int* dest) {
  int i1 = 0;
  int i2 = 0;

  while (i1 != array1len || i2 != array2len) {
    if (i1 == array1len) {
      *dest = array2[i2++];
      dest++;
    } else if (i2 == array2len) {
      *dest = array1[i1++];
      dest++;
    } else if (array1[i1] > array2[i2]) {
      *dest = array2[i2++];
      dest++;
    } else {
      *dest = array1[i1++];
      dest++;
    }
  }
}

void mergesort_r(int* bg, int* temp, int left, int right) {
  if (right - left < 2) return;
  int mid = (left + right) / 2;
  mergesort_r(bg, temp, left, mid);
  mergesort_r(bg, temp, mid, right);

  for (int i = left; i < right; ++i) {
    temp[i] = bg[i];
    print(bg,9);
  }
  merge(temp + left, mid - left, temp + mid, right - mid, bg + left);
}

void mergesort(int* bg, int n) {
  auto temp = new int[n];
  print(bg,9);
  mergesort_r(bg, temp, 0, n);
  delete[] temp;
}

int main(int argc, char *argv[])
{
  int a[] = {7,18,52,20,22,46,51,17,88};
  mergesort(a,9);
  for (const auto& i : a) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
