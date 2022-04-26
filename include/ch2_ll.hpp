#ifndef CHAPTER_TWO_LL_H
#define CHAPTER_TWO_LL_H

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
	LList<T>() {
		head = new LLNode<T>;
		head->next = head;
		head->prev = head;
	}

#endif
