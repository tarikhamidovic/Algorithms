#include<iostream>
#include<set>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>

void loadFileToSet(std::set<std::string>& words) {
  std::string input;
  std::ifstream file{"shakespeare.txt"};
  std::cout << "Loading words to std::set container..." << std::endl;
  while (file >> input) {
    words.insert(input);
  }
  std::cout << "Word loading finished!" << std::endl;
  std::cout << std::endl;
}

void loadFileToVector(std::vector<std::string>& words) {
  std::string input;
  std::ifstream file{"shakespeare.txt"};
  std::cout << "Loading words to std::vector container..." << std::endl;
  while (file >> input) {
    words.push_back(input);
  }
  std::sort(words.begin(), words.end());
  std::cout << "Word loading finished!" << std::endl;
  std::cout << std::endl;
}

bool binary_search(std::vector<std::string>& vec, int begin, int end, std::string word) {
  if (end >= begin) {
    int mid = begin + (end - begin) / 2;
    if (vec[mid] == word) {
      return true;
    }
    else if (vec[mid] > word) {
      return binary_search(vec, begin, mid-1, word);
    }
    else {
      return binary_search(vec, mid+1, end, word);
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  std::set<std::string> mywords;
  std::vector<std::string> mywordsinvector;
  loadFileToSet(mywords);
  loadFileToVector(mywordsinvector);
  bool programRunning = true;
  while (programRunning) {
    std::cout << "Enter word: " ;
    std::string inputword;
    std::cin >> inputword;
    std::cout << std::endl;
    auto now1 = std::chrono::steady_clock::now();
    auto it = mywords.find(inputword);
    auto elapsed1 = std::chrono::steady_clock::now() - now1;
    std::cout << "Searching in std::set container..." << std::endl;
    if (it == mywords.end()) {
      std::cout << "The word " << inputword << " does not exist in the text." << std::endl;
    }
    else {
      std::cout << "The word " << inputword << " does exist in the text." << std::endl;
    }
    std::cout << "Time elapsed for search in std::set: " << elapsed1.count() << "ns" << std::endl;
    std::cout << std::endl;
    // searching in vector
    std::cout << "Searching in std::vector container..." << std::endl;
    auto now2 = std::chrono::steady_clock::now();
    bool found = binary_search(mywordsinvector, 0, mywordsinvector.size()-1, inputword);
    auto elapsed2 = std::chrono::steady_clock::now() - now2;
    if (found) {
      std::cout << "The word " << inputword << " does exist in the text." << std::endl;
    }
    else {
      std::cout << "The word " << inputword << " does not exist in the text." << std::endl;
    }
    std::cout << "Time elapsed for search in std::vector: " << elapsed2.count() << "ns" << std::endl;
    std::cout << std::endl;
    std::cout << "Exit search? (Yes/No): ";
    std::string choice;
    std::cin >> choice;
    if (choice == "Yes" || choice == "yes" || choice == "y") {
      programRunning = false;
    }
  }
  return 0;
}
