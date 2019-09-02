#include<iostream>
#include<string>
#include<vector>

struct Tim {
  Tim(const std::string& ime, const int& points, const int& prgolovi, const int& pogolovi) : naziv(ime), bodovi(points), primljeniGolovi(prgolovi), postignutiGolovi(pogolovi) {}
  std::string naziv;
  int bodovi;
  int primljeniGolovi;
  int postignutiGolovi;
};

void printStats(std::vector<Tim>& vec) {
  std::cout << "-Tim-\t\t-Bodovi-\t-Primljeni_golovi-\t-Postignuti_golovi-" << std::endl;
  for(int i = 0; i < vec.size(); i++)
    std::cout << vec[i].naziv << "\r\t\t   " << vec[i].bodovi << "\r\t\t\t\t\t" << vec[i].primljeniGolovi << "\r\t\t\t\t\t\t\t\t"<< vec[i].postignutiGolovi << std::endl;
}

template<typename T>
void sort(std::vector<Tim>& vec, T func) {
  for(int i = 0; i < vec.size(); i++) {
    for(int j = i; j > 0; j--) {
      if (func(vec[j],vec[j-1])) {
        std::swap(vec[j], vec[j-1]);
      }
    }
  }
}

void insertTeam(std::vector<Tim>& vec) {
  std::cout << "Naziv: " ;
  std::string naziv;
  std::cin >> naziv;
  std::cout << "Bodovi: " ;
  int bodovi;
  std::cin >> bodovi;
  std::cout << "Primljeni golovi: " ;
  int pr_golovi;
  std::cin >> pr_golovi;
  std::cout << "Postignuti golovi: " ;
  int po_golovi;
  std::cin >> po_golovi;
  Tim a{naziv,bodovi,pr_golovi,po_golovi};
  vec.push_back(a);
}

int main(int argc, char *argv[])
{
  std::vector<Tim> teams;
  bool insert = true;
  while (insert) {
    insertTeam(teams);
    std::cout << "Zavrsiti unos? " ;
    std::cout << "Da/Ne: ";
    std::string p;
    std::cin >> p;
    if (p == "Da" || p == "da") {
      insert = false;
    }
  }
  sort(teams, [](const Tim& first, const Tim& second) { return first.naziv < second.naziv; });
  sort(teams, [](const Tim& first, const Tim& second) { return first.postignutiGolovi > second.postignutiGolovi; }); 
  sort(teams, [](const Tim& first, const Tim& second) { return (first.postignutiGolovi - first.primljeniGolovi) > (second.postignutiGolovi - second.primljeniGolovi); }); 
  sort(teams, [](const Tim& first, const Tim& second) { return first.bodovi > second.bodovi; }); 
  std::string lines(75, '-');
  std::cout << lines << std::endl;
  printStats(teams);
  std::cout << lines << std::endl;
  return 0;
}
