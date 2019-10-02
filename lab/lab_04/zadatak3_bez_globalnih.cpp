#include <cstring>
#include <iostream>
#include <vector>

int longest_common_subsequence_r(const char* a, const char* b, int na, int nb) {
  if (na == 0 || nb == 0) {
    return 0;
  }
  if (a[na - 1] == b[nb - 1]) {
    return 1 + longest_common_subsequence_r(a, b, na - 1, nb - 1);
  } else {
    return std::max(longest_common_subsequence_r(a, b, na, nb - 1),
                    longest_common_subsequence_r(a, b, na - 1, nb));
  }
}

int longest_common_subsequence_m_impl(
    const char* a, const char* b, int na, int nb,
    std::vector<std::vector<int>>& lookup_table) {
  if (na == 0 || nb == 0) return 0;
  if (lookup_table[na - 1][nb - 1] > 0) return lookup_table[na - 1][nb - 1];
  if (a[na - 1] == b[nb - 1]) {
    int sol1 =
        longest_common_subsequence_m_impl(a, b, na - 1, nb - 1, lookup_table);
    lookup_table[na - 1][nb - 1] = sol1 + 1;
    return sol1 + 1;
  } else {
    int sol1 =
        longest_common_subsequence_m_impl(a, b, na - 1, nb, lookup_table);
    int sol2 =
        longest_common_subsequence_m_impl(a, b, na, nb - 1, lookup_table);
    lookup_table[na - 1][nb - 1] = std::max(sol1, sol2);
    return lookup_table[na - 1][nb - 1];
  }
}

int longest_common_subsequence_m(const char* a, const char* b, int na, int nb) {
  std::vector<std::vector<int>> lookup_table;
  lookup_table.resize(na + 1);
  for (auto& row : lookup_table) row.resize(nb + 1);
  return longest_common_subsequence_m_impl(a, b, na, nb, lookup_table);
}

int longest_common_subsequence_d(const char* a, const char* b, int na, int nb) {
  std::vector<std::vector<int>> lookup_table;
  lookup_table.resize(na + 1);
  for (auto& row : lookup_table) row.resize(nb + 1);

  for (int i = 0; i <= na; ++i) {
    lookup_table[i][0] = 0;
  }
  for (int i = 0; i <= nb; ++i) {
    lookup_table[0][i] = 0;
  }

  for (int i = 1; i <= na; ++i) {
    for (int j = 1; j <= nb; ++j) {
      if (a[i - 1] == b[j - 1])
        lookup_table[i][j] = lookup_table[i - 1][j - 1] + 1;
      else
        lookup_table[i][j] =
            std::max(lookup_table[i - 1][j], lookup_table[i][j - 1]);
    }
  }
  return lookup_table[na][nb];
}

int main(int argc, char* argv[]) {
  std::string a = "abcdefg";
  std::string b = "abfg";
  std::cout << longest_common_subsequence_d(a.c_str(), b.c_str(), a.size(), b.size())
            << std::endl;
  return 0;
}

// int main(int argc, char* argv[]) {
//   std::cout << longest_common_subsequence_d(argv[1], argv[2],
//   strlen(argv[1]),
//                                             strlen(argv[2]))
//             << std::endl;
//   return 0;
// }
