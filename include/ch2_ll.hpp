#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

#include <stdio.h>

namespace ll {

template<typename T>
class LLNode {
public:
	LLNode(T val) : data(val), next(nullptr), prev(nullptr) {}
	LLNode<T> *next, *prev;
	T data;
};

template<typename T>
class LList {
public:
	LList() : head(nullptr) {}
	LLNode<T> *head;
	void insert_node(LLNode<T> *);
	void delete_node(LLNode<T>*);
	void remove_dups(LLNode<T>*, T);
	void remove_dups();
	void print_nodes();
};

template<typename T>
void LList<T>::insert_node(LLNode<T>* lln){
	if (this->head == nullptr){
		this->head = lln;
		return;
	}
	
	LLNode<T> *llc = this->head;
	while (llc->next != nullptr){
		llc = llc->next;
	}
	llc->next = lln;
	lln->next = nullptr; // ensure for sanity
}

template<typename T>
void LList<T>::delete_node(LLNode<T>* lln){
	if (this->head == nullptr)
		return;
	if (this->head == lln){
		if (this->head->next == nullptr){
			this->head = nullptr;
			return;
		}
		else {
			this->head = this->head->next;
			return;
		}
	}

	auto n = this->head;
	while (n != nullptr) {
		if (n == lln) {
			n->prev->next = n->next;
			n->next->prev = n->prev;
			return;
		}
		n = n->next;
	}
}

template<typename T>
void LList<T>::remove_dups(LLNode<T>* lln, T val){
	if (lln->data == val){
		auto llnn = lln->next;
		this->delete_node(lln);
	}
	if (llnn == nullptr)
		return;
	
	this->remove_dups(llnn, val);
}

template<typename T>
void LList<T>::remove_dups(){
	auto n = this->head;
	while (n->next != nullptr) {
		this->remove_dups(n->next, n.data);
		n = n->next;
	}
	return;
}

// default impl
template<typename T>
void LList<T>::print_nodes() {}

template<>
void LList<int>::print_nodes(){
	auto x = this->head;
	while(x != nullptr){
		printf("data = %d\n", x->data);
		x = x->next;
	}
	return;
}

}
#endif
