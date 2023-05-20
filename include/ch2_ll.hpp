#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

#include <stdio.h>
#include <concepts>
#include <iostream>
#include <iterator>
#include <cstddef>

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
	LList() : head(nullptr), _length(0) {}
	~LList();
	LLNode<T> *head;
	LLNode<T> *tail;
	int cheap_length();
	int length();
	void insert_node(LLNode<T> *);
	void delete_node(LLNode<T>*);
	void remove_dups(LLNode<T>*, T);
	void remove_dups();
	void print_nodes();
	LLNode<T> operator[](int);
	bool operator==(LList<T>&);
	LLNode<T> nth_last(int);
	bool already_linked(LLNode<T> *);
	struct Iterator {
		using iterator_category = std::forward_iterator_tag;
		using difference_type 	= std::ptrdiff_t;
		using value_type 		= LLNode<T>;
		using pointer 			= LLNode<T>*;
		using reference 		= LLNode<T>&;

		Iterator(pointer ptr) : node_ptr(ptr) {}

		reference operator*() const { return node_ptr; }
		pointer operator->() { return node_ptr; }
		// prefix
		Iterator& operator++() 
		// postfix 
		Iterator operator++(int) { Iterator tmp = *this; (*this) = this->next; return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.node_ptr == b.node_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.node_ptr != b.node_ptr; }; 
	private:
		pointer node_ptr;
	}

	Iterator begin() { return Iterator(&head); }
	Iterator end() { }
private:
	int _length;
};

template<std::equality_comparable T>
int LList<T>::cheap_length(){
	return _length;
}

template<std::equality_comparable T>
bool LList<T>::already_linked(LLNode<T> *n){
	LLNode<T> *element = this->head;
	while (element != nullptr){
		if (element == n){
			return true;
		}
		element = element->next;
	}
	return false;
}

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
		this->tail = lln;
	} else {
		LLNode<T> *llc = this->head;
		while (llc->next != nullptr){
			llc = llc->next;
		}
		llc->next = lln;
		lln->prev = llc;
		lln->next = nullptr; // ensure for sanity
	}
	
	this->tail = lln;
	++this->_length;
	return;
	
}

template<std::equality_comparable T>
void LList<T>::delete_node(LLNode<T>* lln){
	if (this->head == nullptr)
		return;
	if (this->tail == lln){
		this->tail == this->tail->prev;
	}
	if (this->head == lln){
		if (this->head->next == nullptr){
			this->head = nullptr;
		}
		else {
			this->head = this->head->next;
		}
		--this->_length;
		return;
	}

	auto n = this->head;
	while (n != nullptr) {
		if (n == lln) {
			if (n->prev != nullptr)
				n->prev->next = n->next;
			if (n->next != nullptr)
				n->next->prev = n->prev;
			--this->_length;
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
    // if (index >= this->length()) {
    //     std::cout << "Array index out of bound, exiting\n";
    //     exit(0);
    // } 

    LLNode<T> *ret = this->head;
    while (index > 0 && ret != nullptr) {
	    ret = ret->next;
	    --index;
    }
	if (index != 0){
		throw std::out_of_range("Index out of the ol bounds!");
	}
    return *ret;
}

template<std::equality_comparable T>
bool LList<T>::operator==(LList<T> &rhs)
{
	LLNode<T> *lhs_e = this->head; 
	LLNode<T> *rhs_e = rhs.head;
	int c = 0;
	
	while (lhs_e != nullptr && rhs_e != nullptr){
		if ((*this)[c].data != rhs[c].data){
			return false;
		}
		++c;
		lhs_e = lhs_e->next;
		rhs_e = rhs_e->next;
	}

	if (lhs_e != nullptr || rhs_e != nullptr){
		return false;
	}

	return true;
}


template<std::equality_comparable T>
LLNode<T> LList<T>::nth_last(int n){
	int i = (length() - n - 1);
	LLNode<T> *ret = this->head;
	while (i > 0 && ret != nullptr) {
		ret = ret->next;
		--i;
	}

	if (i != 0){
		throw std::out_of_range("Index out of bounds, partner...\n");
	}

	return *ret;
}
}
#endif
