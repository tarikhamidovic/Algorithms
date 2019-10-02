#include<iostream>
#include<vector>
#include<algorithm>

struct Voznja {
  int tip;
  int cijena;
  int trajanje;
  int vrijednost;
  Voznja(int T,int c,int t) : tip(T), cijena(c), trajanje(t), vrijednost(trajanje/cijena) {}
  void print() {
    std::cout << "Tip: " << tip << std::endl;
    std::cout << "Cijena: " << cijena << std::endl;
    std::cout << "Trajanje: " << trajanje << std::endl;
  }
};

int find(std::vector<Voznja>& vektor) {
  std::sort(vektor.begin(), vektor.end(), [](Voznja one, Voznja two) { return one.vrijednost > two.vrijednost; });
  int suma = 0;
  int kolicina = 0;
  int apoen = 10;
  for (int i = 0; i < vektor.size(); i++) {
    if (vektor[i].cijena <= apoen && (suma + apoen) <= 10) {
      suma = suma + vektor[i].cijena;
      kolicina = kolicina + vektor[i].trajanje;
      apoen = apoen - vektor[i].cijena;
    }
  }
  return kolicina;
}

int main(int argc, char const *argv[]) {
  std::vector<Voznja> v;
  v.push_back(Voznja(1,10,40));
  v.push_back(Voznja(2,5,18));
  v.push_back(Voznja(3,4,35));
  v.push_back(Voznja(4,2,2));
  v.push_back(Voznja(5,3,4));
  v.push_back(Voznja(6,1,10));
  std::cout<< "Najoptimalnija voznja traje: " << find(v) << std::endl;
  return 0;
}
