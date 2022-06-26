#include <ch2.hpp>
#include <math.h>
namespace practice {
int convertToNum(LList<int> *list){
	int s = list->length, c = 0, r = 0;
	LList<int> tmp = *list;
	while (s - c > 0){
		r += tmp[c].data * pow(10, c);
		++c;
	}
	return r;

}
LList<int>* convertToLList(int ins){
	LList<int> *ret = new LList<int>();
	LLNode<int> *insn;
	int tmp = ins % 10;
	ins /= 10;
	while (tmp) {
		insn = new LLNode<int>(tmp);
		ret->insert_node(insn);
		tmp = ins % 10;
		ins /= 10;
	}
	return ret;
}
}
