#include <ch2.hpp>
#include <math.h>
namespace practice {
int convertToNum(LList<int> *list){
	int s = list->length;
	int c = 0;
	int r = 0;
	LList<int> tmp = *list;
	while (s > 0){
		r += tmp[c].data * pow(10, c);
		--s;
		++c;
	}
	return r;

}
}
