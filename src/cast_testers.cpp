#include <string>
#include <stdio.h>

int main(int argc, char **argv){
	for (int i = 0; i < 256; i++){
		printf("%d = %c\n",i, static_cast<char>(i));
	}
	return 0;
}

