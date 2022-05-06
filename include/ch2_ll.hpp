#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

#include <stdio.h>
#include <concepts>

namespace ll {

template<std::equality_comparable T>
class LLNode {
public:
	LLNode(T val) : next(nullptr), prev(nullptr), data(val) {}
	LLNode<T> *next, *prev;
	T data;
};

template<std::equality_comparable T>
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

template<std::equality_comparable T>
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
	lln->prev = llc;
	lln->next = nullptr; // ensure for sanity
}

template<std::equality_comparable T>
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
			if (n->prev != nullptr)
				n->prev->next = n->next;
			if (n->next != nullptr)
				n->next->prev = n->prev;
			return;
		}
		n = n->next;
	}
}

template<std::equality_comparable T>
void LList<T>::remove_dups(LLNode<T>* lln, T val){
	if (lln == nullptr)
		return;

	auto llnn = lln->next;
	if (lln->data == val){
		this->delete_node(lln);
	}
	
	this->remove_dups(llnn, val);
}

template<std::equality_comparable T>
void LList<T>::remove_dups(){
	auto n = this->head;
	while (n != nullptr) {
		this->remove_dups(n->next, n->data);
		n = n->next;
	}
	return;
}

// default impl
template<std::equality_comparable T>
void LList<T>::print_nodes() {}

template<>
inline void LList<int>::print_nodes(){
	auto x = this->head;
	while(x != nullptr){
		printf("data = %d\n", x->data);
		x = x->next;
	}
	return;
}

}
#endif
