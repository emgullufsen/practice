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
	char str3[] = {'E','V','A','N','N','E','\0'};
	char str4[] = {'D','O','G','G','Y','\0'};
	printf("%s\n", reverse_cstr(str3));
	printf("%s\n", reverse_cstr(str4));
	printf("%s\n", str3);
	return 0;
}
