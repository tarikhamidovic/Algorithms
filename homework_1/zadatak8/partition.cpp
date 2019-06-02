#include<iostream>
#include<vector>

template<typename Iter, typename P>
Iter partition(Iter begin, Iter end, const P& p) {
  Iter returnIter;
  for (auto it = begin; it != end; it++) {
    if (p(*it)) 
      continue;
    for (auto it2 = it + 1; it2 != end; it2++ ) {
      if (p(*it2)) {
        std::swap(*it, *it2);
        returnIter = it + 1;
        break;
      }
    }
  }
  return returnIter;
}

int main(int argc, char *argv[])
{
  std::vector<int> v{0,5,3,10,11,4,7,1,2,20};
  auto temp = [] (int a) {return a < 4;};
  auto iter = partition(v.begin(), v.end(), temp);
  for (const auto& el : v) 
    std::cout << el << ' ';
  std::cout << std::endl;
  std::cout << "Return iter: " << *iter << std::endl;
  return 0;
}
