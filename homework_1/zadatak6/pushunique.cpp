#include<iostream>
#include<vector>

bool push_unique(std::vector<int>& vec, int value) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == value) {
      return false;
    }
  }
  vec.push_back(value);
  return true;
}

int main(int argc, char *argv[])
{
  std::vector<int> v{1,2,3,4};
  std::cout << push_unique(v,3) << std::endl;
  return 0;
}
