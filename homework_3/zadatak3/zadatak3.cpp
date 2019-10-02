#include <iostream>

// Credits to Adin Glumcevic for helping me out on this one :)
int maxSubarrayLength_r(int* array, int n) {
  int len = 1;
  int max_len = len;
  for (int i = 1; i < n; i++) {
    if (array[i] <= array[i-1]) {
      int temp_len = maxSubarrayLength_r(array+i, n-i);
      if (temp_len > max_len) 
        max_len = temp_len;
    } 
    else {
      len++;
      if (len > max_len) 
        max_len = len;;
    }
  }
  return max_len;
}

int maxSubarrayLength_dp(int* array, int n) {
  int max_len = 1;
  for (int i = 0; i < n-1; i++) {
    int temp_len = 1;
    for (int j = i; j < n-1; j++) {
      if (array[j+1] > array[j]) 
        temp_len++;
    }
    if (temp_len > max_len) 
      max_len = temp_len;
  }
  return max_len;
}

int main(int argc, char *argv[])
{
  int a[] = {9, 21, 8, 32, 20, 40, 59};
  std::cout << maxSubarrayLength_r(a, 7) << std::endl;
  std::cout << maxSubarrayLength_dp(a, 7) << std::endl;
  return 0;
}
