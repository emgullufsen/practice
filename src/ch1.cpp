/* Chapter 01 */

#include <string>
#include <ch1.hpp>
/*
* 1.1 Implement an algorithm to determine if a string has all unique characters.
* What if you can not use additional data structures?
*/

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

char *
reverse_cstr(char *inp){
	
}
