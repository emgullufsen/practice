/* Chapter 01 */
#include <cstring>
#include <string>
#include <ch1.hpp>
#include <iterator>
#include <cstddef>
#include <vector>
#include <set>

/*
* 1.1 Implement an algorithm to determine if a string has all unique characters.
* What if you can not use additional data structures?
*/
namespace practice {

bool
unique_chars(std::string& inp){
	int num_in[NUM_ASCII_CHARS] = {};
	for (auto &i : inp){
		num_in[static_cast<uint8_t>(i)]++;
	}

	for (auto i : num_in){
		if (i > 1)
			return false;
	}

	return true;
}

/*
* 1.2 Write code to reverse a C-style string. (C-string means that "abcd" is
* represented as five characters, including the null character.)
*/

char *
reverse_cstr(char *inp){
	int sz = strlen(inp);
	int mid = (sz - 1) / 2;
	char temp;
	for (int i = 0; i <= mid; ++i){
		temp = inp[(sz - 1 - i)];
		inp[(sz - 1 - i)] = inp[i];
		inp[i] = temp;
	}
	return inp;
}

/*
* 1.3 Design an algorithm and write code to remove the duplicate characters in a
* string without using any additional buffer.
*/
std::string&
remove_dups(std::string& str){
	for (std::string::size_type i = 0; i < str.size(); ++i){
		std::string::size_type j = i + 1;
		while (j < str.size()){
			if (str[i] == str[j])
				str.erase(j,1);
			else
				++j;
		}
	}
	return str;
}

/*
* 1.4 Write a method to decide if two strings are anagrams or not
*/
bool
anagrams(std::string& inp1, std::string& inp2){
	int num_in1[NUM_ASCII_CHARS] = {};
	int num_in2[NUM_ASCII_CHARS] = {};
	for (auto& i : inp1){
		num_in1[static_cast<uint8_t>(i)]++;
	}
	for (auto& i : inp2){
		num_in2[static_cast<uint8_t>(i)]++;
	}
	for (int i = 0; i < NUM_ASCII_CHARS; ++i){
		if (num_in1[i] != num_in2[i])
			return false;
	}
	return true;
}

/*
* 1.5 Write a method to replace all spaces in a string with '%20'
*/
std::string&
replace_spaces(std::string& inp){
	for (std::string::size_type i = 0; i < inp.size(); ++i){
		if (inp[i] == ' ')
			inp.replace(i,1,"%20");
	}
	return inp;
}

/*
* 1.6 is in header file ch1.hpp (unspecialized templated function)
*/

/*
* 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its
* entire row and column is set to 0.
*/

void
row_col_zero(matrix& in_matrix){
	std::set<int> zero_rows;
	std::set<int> zero_cols;
	for (int i = 0; i < in_matrix.size(); ++i){
		for (int j = 0; j < in_matrix[i].size(); ++j){
			if (in_matrix[i][j] == 0){
				zero_rows.insert(i);
				zero_cols.insert(j);
			}
		}
	}

	for (auto& r: zero_rows){
		for (int jc = 0; jc < in_matrix[r].size(); ++jc){
			in_matrix[r][jc] = 0;
		}
	}

	for (auto& c: zero_cols){
		for (int ic = 0; ic < in_matrix.size(); ++ic){
			in_matrix[ic][c] = 0;
		}
	}
}

} // namespace practice
