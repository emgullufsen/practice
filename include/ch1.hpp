#include <string>
#include <cstddef>
namespace practice {
#define NUM_ASCII_CHARS 256
bool unique_chars(std::string&);
char *reverse_cstr(char *);
std::string& remove_dups(std::string&);
bool anagrams(std::string&, std::string&);
std::string& replace_spaces(std::string&);
template <size_t N> void rotate_90(std::byte[N][N][4]);
}
