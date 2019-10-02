#include<iostream>
#include<chrono>

int main(int argc, char *argv[])
{
  auto now = std::chrono::system_clock::now();
  std::cout << "Hello world" << std::endl;
  auto elapsed = std::chrono::system_clock::now() - now;
  return 0;
}
