#include <string>
#include <iostream>

namespace practice {
std::string&
remove_dups(std::string&);
}

int main(int argc, char **argv){
	std::string str1("eric gullufsen");
	std::cout << practice::remove_dups(str1) << std::endl;
	return 0;
}

