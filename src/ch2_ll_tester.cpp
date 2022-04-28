#include "../include/ch2_ll.hpp"
#include <stdio.h>

using namespace ll;

int main(int argc, char **argv){
	LLNode<int> *a0 = new LLNode<int>(0);
	LLNode<int> *a1 = new LLNode<int>(1);
	LLNode<int> *a2 = new LLNode<int>(2);

	LList<int> *li = new LList<int>;
	li->insert_node(a0);
	li->insert_node(a1);
	li->insert_node(a2);

	auto x = li->head;
	while(x != nullptr){
		printf("data = %d\n", x->data);
		x = x->next;
	}

	return 0;

}
