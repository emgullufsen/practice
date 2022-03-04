/* Chapter 01 */

#include <string>
#include <ch1.hpp>
#include <iterator>

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
}
