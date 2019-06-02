#include<iostream>
#include<string>

bool palindrom(std::string mystring) {
  if (mystring.size() == 0 || mystring.size() == 1) {
    return true;
  }
  if (mystring[0] != mystring[mystring.size()-1]) {
    return false;
  }
  mystring.erase(0,1);
  mystring.pop_back();
  return palindrom(mystring);
}

int main(int argc, char *argv[])
{
  std::cout << palindrom("an") << std::endl;
  return 0;
}
