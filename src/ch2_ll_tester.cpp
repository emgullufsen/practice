#include "../include/ch2_ll.hpp"
#include <stdio.h>

using namespace ll;

int main(int argc, char **argv){
	LLNode<int> *a0 = new LLNode<int>(0);
	LLNode<int> *a1 = new LLNode<int>(1);
	LLNode<int> *a2 = new LLNode<int>(2);
	LLNode<int> *a3 = new LLNode<int>(3);
	LLNode<int> *a4 = new LLNode<int>(3);
	LLNode<int> *a5 = new LLNode<int>(4);
	LLNode<int> *a6 = new LLNode<int>(4);
	LLNode<int> *a7 = new LLNode<int>(1);
	LLNode<int> *a8 = new LLNode<int>(2);

	LList<int> *li = new LList<int>;
	li->insert_node(a0);
	li->insert_node(a1);
	li->insert_node(a2);
	li->insert_node(a3);
	li->insert_node(a4);
	li->insert_node(a5);
	li->insert_node(a6);
	li->insert_node(a7);
	li->insert_node(a8);

	// starting point
	printf("printing li after insertions\n");

	li->print_nodes();

	// delete one of the nodes
	li->delete_node(a5);

	printf("should have deleted one of the 4's\n");

	li->print_nodes();

	// remove duplicates
	li->remove_dups();

	printf("should have removed duplicates\n");

	li->print_nodes();

	return 0;

}
