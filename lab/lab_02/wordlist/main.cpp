#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std::chrono;

// TODO replace the std::set<string> in this example with std::vector<string>
// you may need the following std algorithms
// std::binary_search
// std::sort
// std::unique
// std::vector::erase

int main() {
  std::set<std::string> words;
  std::ifstream fin{"shakespeare.txt"};
  std::string input;
  while (fin >> input) {
    words.insert(input);
  }
  std::cout << "Loading the file has finished." << std::endl;
  std::cout << "Enter word:" << std::endl;

  while (std::cin >> input) {
    std::cout << "Word: " << input << std::endl;

    auto now = std::chrono::system_clock::now();
    // benchmark
    auto it = words.find(input);
    auto found = it != words.end();
    //
    auto elapsed = std::chrono::system_clock::now() - now;

    if (found) {
      std::cout << "Words exists in dictionary" << std::endl;
    } else {
      std::cout << "Words does not exists in dictionary" << std::endl;
    }
    std::cout << "Duration: " << elapsed.count() << " ns" << std::endl;
    std::cout << "Duration: " << duration_cast<milliseconds>(elapsed).count()
              << " ms" << std::endl;
  }
}
