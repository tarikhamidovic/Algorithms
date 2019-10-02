#include <iostream>
#include <string>
#include <vector>

void count_postmarks_r(int n, int& fives, int& threes) {
  if (n == 8) {
    fives = 1;
    threes = 1;
    return;
  }
  if (n == 9) {
    fives = 0;
    threes = 3;
    return;
  }
  if (n == 10) {
    fives = 2;
    threes = 0;
    return;
  }
  if (n == 11) {
    fives = 1;
    threes = 2;
    return;
  }
  count_postmarks_r(n - 5, fives, threes);
  fives += 1;
}

void count_postmarks(int n, int& fives, int& threes) {
  std::vector<int> fives_array;
  std::vector<int> threes_array;
  fives_array.resize(n + 1);
  threes_array.resize(n + 1);

  // All recursion base cases are put as initial values
  fives_array[8] = 1;
  threes_array[8] = 1;
  fives_array[9] = 0;
  threes_array[9] = 3;
  fives_array[10] = 2;
  threes_array[10] = 0;
  fives_array[11] = 1;
  threes_array[11] = 2;

  // body of the recursion becomes the body of the loop
  for (int i = 12; i <= n; i++) {
    fives_array[i] = fives_array[ i - 5] + 1;
    threes_array[i] = threes_array[ i - 5];
  }

  fives = fives_array[n];
  threes = threes_array[n];
}

int main() {
  int fives;
  int threes;
  int n;

  n = 20;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  n = 21;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  n = 22;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  n = 23;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  n = 24;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  n = 25;
  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;

  return 0;
}
