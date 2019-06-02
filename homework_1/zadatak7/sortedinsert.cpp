#include<iostream>
#include<vector>

void sorted_insert(std::vector<int>& vec, int value) {
  int b = 0;
  int e = vec.size() - 1;
  int mid = 0;
  if (value >= vec[e]) {
    auto it = vec.end();
    vec.insert(it,value);
    return;
  }
  else if (value <= vec[b]) {
    auto it = vec.begin();
    vec.insert(it,value);
    return;
  }
  else {
    while (b != e) {
      mid = (b + e) / 2;
      if (value >= vec[mid] && value <= vec[mid + 1]) {
        auto it = vec.begin() + mid + 1;
        vec.insert(it,value);
        return;
      }
      else {
        if (value < vec[mid]) {
          e = mid;
        }
        else {
          b = mid;
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{
  std::vector<int> v{1,2,3,4,6};
  sorted_insert(v,5);
  for (const auto& el : v) std::cout << el << ' ';
  std::cout << std::endl;
  return 0;
}
