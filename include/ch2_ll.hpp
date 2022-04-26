#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

namespace ll {

template<typename T>
class LLNode<T> {
public:
	LLNode<T> *next, *prev;
	T data;
}

template<typename T>
class LList<T> {
public:
	LLNode<T> *head;
	LList<T>();
	insert_node(LLNode<T>);
}
#endif
