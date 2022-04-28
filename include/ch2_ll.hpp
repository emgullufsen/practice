#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

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

}
#endif
