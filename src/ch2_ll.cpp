namespace ll {

template<typename T>
LList<T>::insert_node(LLNode<T> lln){
	if (this->head == NULL){
		this->head = lln;
		return;
	}
	
	LLNode<T> llc = this->head;
	while (llc->next != NULL){
		llc = llc->next;
	}
	llc->next = lln;
	lln->next = NULL; // ensure for sanity
}

}
