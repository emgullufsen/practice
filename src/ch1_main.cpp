#include <ch1.hpp>
#include <iostream>
#include <string>

void
print_res(bool inb){
	std::cout << (inb ? "TRUE" : "FALSE") << std::endl;
}

int
main(int argc, char **argv){
	std::string s1 = "eric gullufsen";
	std::string s2 = "uniqtae";
	print_res(unique_chars(s1));
	print_res(unique_chars(s2));
	return 0;
}
