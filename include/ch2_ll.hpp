#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

namespace ll {

template<typename T>
class LLNode {
public:
	LLNode(T val) : data(val), next(nullptr), prev(nullptr) {}
	LLNode<T> *next, *prev;
	T data;
}

template<typename T>
class LList {
public:
	LList() : head(nullptr) {}
	LLNode<T> *head;
	insert_node(LLNode<T>);
}
#endif
