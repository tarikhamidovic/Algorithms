#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// not stable
void selectionsort(int* bg, int n) {
  for (int i = 0; i < n; i++) {
    int minimal = i;
    for (int j = i; j < n; j++) {
      if (bg[j] < bg[minimal]) {
        std::swap(minimal, j);
      }
    }
    std::swap(bg[minimal], bg[i]);
  }
}

// stable
void bubblesort(int* bg, int n) {
  for (int i = n; i >= 0; --i) {
    bool swapped = 0;
    for (int j = 1; j < i; ++j) {
      if (bg[j] < bg[j - 1]) {
        std::swap(bg[j], bg[j - 1]);
        swapped = 1;
      }
    }
    if (!swapped) break;
  }
}

// stable
void insertionsort(int* a, int n) {
  for (int i = 1; i < n; ++i)
    for (int j = i; j != 0 && a[j] < a[j - 1]; --j) std::swap(a[j - 1], a[j]);
}

// one step for shell sort
void insertionsort_var(int* a, int n, int increment) {
  for (int i = increment; i < n; i += increment)
    for (int j = i; j >= increment && a[j] < a[j - increment]; j -= increment)
      std::swap(a[j - increment], a[j]);
}

// unstable
void shellsort(int* i, int n) {
  for (int k = n / 2; k > 2; k /= 2) {
    for (int b = 0; b < k; ++b) insertionsort_var(i + b, n - b, k);
  }
  insertionsort_var(i, n, 1);
}

// merges two sorted subarrays
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

// stable
// there exists an inplace implementation
void mergesort_r(int* bg, int* temp, int left, int right) {
  if (right - left < 2) return;
  int mid = (left + right) / 2;
  mergesort_r(bg, temp, left, mid);
  mergesort_r(bg, temp, mid, right);

  for (int i = left; i < right; ++i) temp[i] = bg[i];
  merge(temp + left, mid - left, temp + mid, right - mid, bg + left);
}

void mergesort(int* bg, int n) {
  auto temp = new int[n];
  mergesort_r(bg, temp, 0, n);
  delete[] temp;
}

// unstable
void quicksort(int* bg, int n) {
  if (n <= 1) return;
  int pivot_index = n / 2;
  std::swap(bg[pivot_index], bg[n - 1]);

  // Alternative
  int left = -1;
  int right = n - 1;
  do {
  	while (bg[++left] < bg[n-1]);
  	while ((left < right) && bg[n-1] < bg[--right]);
  	std::swap(bg[left], bg[right]);
  } while (left < right);
  std::swap(bg[left], bg[n - 1]);
  // //
  // Alternative
  // auto iter = std::partition(
  //     bg, bg + n - 1, [bg, n](auto& element) { return element < bg[n - 1]; });
  // int left = iter - bg;
  // std::swap(*iter, bg[n - 1]);
  // //

  quicksort(bg, left);
  quicksort(bg + left + 1, n - left - 1);
}

int main(int argc, char* argv[]) {
  int v[20];
  for (int i = 0; i < 20; i++) {
    v[i] = rand() % 100;
  }

  quicksort(v, 20);

  for (int i = 0; i < 20; i++) {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
}

