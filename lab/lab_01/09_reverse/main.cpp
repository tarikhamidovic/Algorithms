#include <iostream>
#include <chrono>

// print a reversed string
void print_reverse(const std::string& s) {
  if (s.size() < 1) {
    std::cout << s;
    return;
  }
  print_reverse(std::string{s.begin() + 1, s.end()}); 
  std::cout << s.front();
}

// reverse a string
std::string reverse(std::string s) {
  if (s.size() == 1) return s;
  return s.back() + reverse( std::string{s.begin(), s.end() - 1} );
}


template <typename I>
void reverse_inplace(I begin, I end) {
  if (begin > end) return ;
  std::swap(*begin, *(end - 1));
  reverse_inplace(begin + 1, end - 1);
}

void reverse_inplace(char* s, int length) {
  if (length <= 0) return;
  std::swap(s[0], s[length - 1]);
  reverse_inplace(s + 1, length - 2);
}

int main() {
  std::string s = "algoritam";
  print_reverse(s);
  std::cout << std::endl;

  reverse_inplace(s.begin(), s.end());
  std::cout << s <<  std::endl;
}
