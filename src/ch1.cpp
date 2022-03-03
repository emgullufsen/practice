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
remove_dups(std::string& inp){
	int len = inp.length();
	for (int i = 0; i < len; ++i){
		for (int j = i + 1; i < len; ++j){
			if (inp[i] == inp[j]){
				inp.erase(j,1);
				--len;
			}
		}
	}
	return inp;
}
}
