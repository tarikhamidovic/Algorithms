#include <iostream>

// what will happen in the following function
void frame_count(int n) {
  std::cout << "Frame " << n << std::endl;
  char array[512];
  frame_count(n + 1);
}

int main() {
  frame_count(0);
}
