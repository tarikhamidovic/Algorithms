#include <iostream>

void print_binary_r(std::string& binary, int length) {
  if (binary.size() == length) {
    std::cout << binary << std::endl;
    return;
  }
  // TODO finish recursion so it prints all binary numbers of given length
}

// TODO when the above function is done, wrap the call to above function here. 
void print_binary(int lenght) {
}

int main()
{
  std::string help;
  print_binary_r(help, 8);
  
  return 0;
}
