#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

#include <stdio.h>
#include <concepts>
#include <iostream>

namespace ll {

template<std::equality_comparable T>
class LLNode {
public:
	LLNode(T val) : next(nullptr), prev(nullptr), data(val) {}
	LLNode<T> *next, *prev;
	T data;
	void remove_from_list();
};

template<std::equality_comparable T>
void LLNode<T>::remove_from_list() {
	next->prev = prev;
	prev->next = next;

	return;
}

template<std::equality_comparable T>
class LList {
public:
	LList() : head(nullptr) {}
	~LList();
	LLNode<T> *head;
	int length();
	void insert_node(LLNode<T> *);
	void delete_node(LLNode<T>*);
	void remove_dups(LLNode<T>*, T);
	void remove_dups();
	void print_nodes();
	LLNode<T> operator[](int);
	bool operator==(LList<T>&);
	LLNode<T> nth_last(int);
};

template<std::equality_comparable T>
int LList<T>::length() {
	LLNode<T> *element = this->head;
	int r = 0;
	while (element != nullptr){
		element = element->next;
		r++;
	}
	return r;
}

template<std::equality_comparable T>
LList<T>::~LList() {
	if (head == nullptr)
		return;

	LLNode<T> *tmp;
	LLNode<T> *n = head;
	while (n != nullptr) {
		tmp = n->next;
		delete n;
		n = tmp;
	}
	return;
}

template<std::equality_comparable T>
void LList<T>::insert_node(LLNode<T>* lln){
	if (this->head == nullptr){
		this->head = lln;
	} else {
		LLNode<T> *llc = this->head;
		while (llc->next != nullptr){
			llc = llc->next;
		}
		llc->next = lln;
		lln->prev = llc;
		lln->next = nullptr; // ensure for sanity
	}
	//++this->length;
	return;
	
}

template<std::equality_comparable T>
void LList<T>::delete_node(LLNode<T>* lln){
	if (this->head == nullptr)
		return;
	if (this->head == lln){
		if (this->head->next == nullptr){
			this->head = nullptr;
		}
		else {
			this->head = this->head->next;
		}
		//--this->length;
		return;
	}

	auto n = this->head;
	while (n != nullptr) {
		if (n == lln) {
			if (n->prev != nullptr)
				n->prev->next = n->next;
			if (n->next != nullptr)
				n->next->prev = n->prev;
			//--this->length;
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

template<std::equality_comparable T>
LLNode<T> LList<T>::operator[](int index)
{
    if (index >= this->length()) {
        std::cout << "Array index out of bound, exiting\n";
        exit(0);
    } 

    LLNode<T> *ret = this->head;
    while (index > 0) {
	    ret = ret->next;
	    --index;
    }
    return *ret;
}

template<std::equality_comparable T>
bool LList<T>::operator==(LList<T> &rhs)
{
	std::cout << "HEY FROM == OPERATOR!!!\n";
	if (this->length() != rhs.length()){
		std::cout << "NOPE FOR LENGTH\n";
		return false;
	}

	for (int c = 0; c < this->length(); c++){
		if ((*this)[c].data != rhs[c].data){
			std::cout << "NOPE FOR DATA!!\n";
			return false;
		}
	}

	return true;
}


template<std::equality_comparable T>
LLNode<T> LList<T>::nth_last(int n){
	if (n > (length() - 1)) {
		std::cout << "too far back in array index, exiting\n";
		exit(0);
	}
	int i = (length() - n - 1);
	LLNode<T> *ret = this->head;
	while (i > 0) {
		ret = ret->next;
		--i;
	}
	return *ret;
}
}
#endif
