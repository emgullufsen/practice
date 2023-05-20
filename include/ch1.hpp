#include <cstddef>
#include <string>
#include <vector>
namespace practice {
#define NUM_ASCII_CHARS 256
bool unique_chars(std::string &);
char *reverse_cstr(char *);
std::string &remove_dups(std::string &);
bool anagrams(std::string &, std::string &);
std::string &replace_spaces(std::string &);
template <size_t N> void rotate_90(std::byte (&in_matrix)[N][N][4]) {
  std::byte save_matrix[N][N][4];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int u = 0; u < 4; ++u) {
        save_matrix[i][j][u] = in_matrix[i][j][u];
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int u = 0; u < 4; ++u) {
        in_matrix[i][j][u] = save_matrix[N - j - 1][i][u];
      }
    }
  }
}
using matrix = std::vector<std::vector<int>>;
void row_col_zero(matrix &);
bool is_rotation(std::string &, std::string &);
} // namespace practice
