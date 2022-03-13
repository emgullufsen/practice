/* Chapter 01 */
#include <cstring>
#include <string>
#include <ch1.hpp>
#include <iterator>
#include <cstddef>

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
* 1.6 Given an image represented by an NxN matrix, where each pixel in the image
* is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this
* in place?
*/
template<size_t N>
void
rotate_90(std::byte in_matrix[N][N][4]){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			for (int u = 0; u < 4; ++u){
				in_matrix[i][j][u] = in_matrix[N - j][i][u];
			}
		}
	}
}

} // namespace practice
