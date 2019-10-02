#include <numeric>
#include <iostream>
#include <vector>

void print(std::vector<int>& throws, int sum) {
  for (auto& t : throws) std::cout << t << ", ";
  std::cout << "Sum is: " << sum << std::endl;
}

void dice(int n, int sum, int max_sum, std::vector<int> throws) {
  if (n == 0) {
    print(throws, sum);
    return;
  }
  for (int i = 1; i < 7; i++) {
    throws.push_back(i);
    dice(n - 1, sum + i, max_sum, throws);
    throws.pop_back();
  }
}

int main() {
  std::vector<int> throws;
  dice(2, 0, 5, throws);

  return 0;
}
