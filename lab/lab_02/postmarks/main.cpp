#include <iostream>
#include <string>

void count_postmarks(int n, int& fives, int& threes) {
  if (n == 8) { fives = 1; threes = 1; }
  // TODO finish this for an arbitrary n >= 8
}

int main() { 

  int fives;
  int threes;
  int n = 8;

  count_postmarks(n, fives, threes);
  std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;

  // TODO: remove comment and verify it works
  // n = 20;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  // n = 21;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  // n = 22;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  // n = 23;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  // n = 24;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  // n = 25;
  // count_postmarks(n, fives, threes);
  // std::cout << n << " = 5 * " << fives << " + 3 * " << threes << std::endl;
  
  return 0; 
}
