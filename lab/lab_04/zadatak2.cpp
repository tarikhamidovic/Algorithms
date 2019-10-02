#include <iostream>
#include <vector>
#include <string>

// Staircase problem

// first step - recursion
int staircase_r(int n) {
  if (n == 3) return 4;
  if (n == 2) return 2;
  if (n == 1) return 1;

  return staircase_r(n - 1) 
    + staircase_r(n - 2)
    + staircase_r(n -3);
}

// Memoisation
// Koraci:
// 10 Uzeti rekurzivno rješenje
// 20 Na početku funkcije provjeriti da li se vrijednost nalazi u tabeli
// 30 U tijelu rekurzije na svakom mjestu gdje se vraćala vrijednost, spremamo
//    vrijednost u tabelu.
// 40 Vraćamo vrijednost iz tabele
int staircase_mem_impl(int n, std::vector<int>& lookup_table) {
  if (lookup_table[n] != 0) return lookup_table[n];

  if (n == 3) { lookup_table[n] = 4; }
  if (n == 2) { lookup_table[n] = 2; }
  if (n == 1) { lookup_table[n] = 1; }

  lookup_table[n] = staircase_r(n - 1) 
    + staircase_r(n - 2)
    + staircase_r(n -3);

  return lookup_table[n];
}

int staircase_mem(int n) {
  std::vector<int> v;
  v.reserve(n+1); 
  return staircase_mem_impl(n, v);
}

// Dynamic programming
// Koraci:
// Napraviti tabelu kao kod memoizacije.
// Svi bazni slučajevi rekurzije se odmah spremaju u tabelu.
// Pravi se petlja koja ide od prvog nebaznog slučaja do tražene vrijednosti.
// Tijelo rekurzije postaje tijelo petlje. Poziv funkcije mijenjamo s indeksiranjem
// u tabelu. Vraćanje iz funkcije mijenjamo sa spremanjem u tabelu.
// Vraćamo zadnju vrijednost. 
int staircase_dyn(int n) {

  std::vector<int> v;
  v.reserve(n+1); 

  v[3] = 4;
  v[2] = 2;
  v[1] = 1;

  for(int i = 4; i <= n; ++i) {
    v[i] = v[i - 1] +  v[i - 2] + v[i -3];
  }

  return v[n];
}

int main() {
  int n = 8;
  std::cout << staircase_r(n) << std::endl;
  std::cout << staircase_mem(n) << std::endl;
  std::cout << staircase_dyn(n) << std::endl;
}
