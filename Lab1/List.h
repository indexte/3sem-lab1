#pragma once

//template<typename T>
//class List
//{
//public:
//	List();
//
//	void pushBack(T data);
//	int getSize();
//	T& operator[](const int index);
//	void popFront();
//	void pushFront(T data);
//	void insert(T data, int index);
//	void removeAt(int index);
//
//private:
//
//	template<typename T>
//	class Node
//	{
//	public:
//		Node* pNext;
//		T data;
//
//		Node(T data = T(), Node* pNext = nullptr) {
//			this->data = data;
//			this->pNext = pNext;
//		}
//	};
//	int size;
//	Node<T>* head;
//};
//
//template<typename T>
//List<T>::List() {
//	size = 0;
//	head = nullptr;
//}
//
//template<typename T>
//void List<T>::pushBack(T data) {
//	if (head == nullptr) {
//		head = new Node<T>(data);
//	}
//	else {
//		Node<T>* current = this->head;
//
//		while (current->pNext != nullptr) {
//			current = current->pNext;
//		}
//		current->pNext = new Node<T>(data);
//	}
//
//	size++;
//}
//
//template<typename T>
//inline int List<T>::getSize() {
//	return size;
//}
//
//template<typename T>
//T& List<T>::operator[](const int index) {
//	int counter = 0;
//
//	Node<T>* current = this->head;
//
//	while (current != nullptr) {
//		if (counter == index) {
//			return current->data;
//		}
//		current = current->pNext;
//		counter++;
//	}
//}
//
//template<typename T>
//void List<T>::popFront() {
//	Node<T>* temp = head;
//
//	head = head->pNext;
//
//	delete temp;
//
//	size--;
//}
//
//template<typename T>
//void List<T>::pushFront(T data) {
//	head = new Node<T>(data, head);
//	size++;
//}
//
//template<typename T>
//void List<T>::insert(T data, int index) {
//	if (index == 0) {
//		pushFront(data);
//	}
//	else {
//		Node<T>* previous = this->head;
//
//		for (int i = 0; i < index - 1; i++)
//		{
//			previous = previous->pNext;
//		}
//
//		Node<T>* newNode = new Node<T>(data, previous->pNext);
//
//		previous->pNext = newNode;
//
//		size++;
//	}
//}
//
//template<typename T>
//void List<T>::removeAt(int index) {
//	if (index == 0) {
//		popFront();
//	}
//	else {
//		Node<T>* previous = this->head;
//		for (int i = 0; i < index - 1; i++) {
//			previous = previous->pNext;
//		}
//
//		Node<T>* toDelete = previous->pNext;
//		previous->pNext = toDelete->pNext;
//		delete toDelete;
//		size--;
//	}
//}


template <typename T>
class CList {
public:
	CList* pNext;
	CList* pPrev;
	T data;

	CList(T val) {
		pNext = NULL;
		pPrev = NULL;
		data = val;
		//cout << "in constructor" << endl;
	}
	CList(T val, CList<T>* pPrev, CList<T>* pNext) {
		this->data = val;
		this->pNext = pNext;
		this->pPrev = pPrev;
		//cout << "in constructor 2" << endl;
	}
	~CList() {
		if (this->pNext)
			delete this->pNext;
		//cout << "in destructor" << endl;
	}
	void printList() {
		CList<T>* tmp = this;
		while (tmp) {
			cout << tmp->data << "->";
			tmp = tmp->pNext;
		}
		cout << endl;
	}
};
template <typename T>
class CFuncList {
private:
	CList<T>* begin;
	CList<T>* end;
public:
	CFuncList(T firstEl) {
		begin = new CList<T>(firstEl);
		end = begin;
	}
	void printFuncList() {
		begin->printList();
	}
	void addEl(T val) {
		CList<T>* tmp = new CList<T>(val, end, NULL);
		end->pNext = tmp;
		//tmp->prev = end;
		end = tmp;
		cout << "prev" << end->pPrev->data << endl;
		cout << "this" << end->data << endl;
		//end->next = NULL;
	}
	void insertionSort(CList<T>* current) {
		CList<T>* curr = current;
		T tmp;
		while (curr->pPrev) {
			if (curr->pPrev->data > curr->data) {
				tmp = curr->data;
				curr->data = curr->pPrev->data;
				curr->pPrev->data = tmp;
			}
			curr = curr->pPrev;
		}

	}
	void insertionSortList() {
		CList<T>* current = begin;
		current = current->pNext;
		while (current) {
			insertionSort(current);
			current = current->pNext;
		}
	}
	void swap(int* a, int* b) {
		int t = *a; *a = *b; *b = t;
	}
	CList<T>* partition(CList<T>* b, CList<T>* e) {
		int line = e->data;
		CList<T>* i = b->pPrev;
		for (CList<T>* j = b; j != e; j = j->pNext) {
			if (j->data <= line) {
				i = (i == NULL) ? b : i->pNext;
				swap(&(i->data), &(j->data));
			}
		}
		i = (i == NULL) ? b : i->pNext;
		swap(&(i->data), &(e->data));
		return i;
	}
	void quickSort(CList<T>* beg, CList<T>* en) {
		if (en != NULL && beg != en && beg != en->pNext) {
			CList<T>* part = partition(beg, en);
			quickSort(beg, part->pPrev);
			quickSort(part->pNext, en);
		}
	}
	void quickSort() {
		quickSort(begin, end);
	}
	CList<T>* sortedMerge(CList<T>* a, CList<T>* b) {
		CList<T>* result = NULL;
		if (a == NULL)
			return (b);
		else if (b == NULL)
			return (a);
		if (a->data <= b->data) {
			result = a;
			result->pNext = sortedMerge(a->pNext, b);
		}
		else {
			result = b;
			result->pNext = sortedMerge(a, b->pNext);
		}
		return (result);
	}
	void frontBackSplit(CList<T>* source, CList<T>** frontRef, CList<T>** backRef) {
		CList<T>* fast;
		CList<T>* slow;
		slow = source;
		fast = source->pNext;
		while (fast != NULL) {
			fast = fast->pNext;
			if (fast != NULL) {
				slow = slow->pNext;
				fast = fast->pNext;
			}
		}
		*frontRef = source;
		*backRef = slow->pNext;
		slow->pNext = NULL;
	}
	void mergeS(CList<T>** headRef) {
		CList<T>* head = *headRef;
		CList<T>* a;
		CList<T>* b;
		if ((head == NULL) || (head->pNext == NULL)) {
			return;
		}
		frontBackSplit(head, &a, &b);
		mergeS(&a);
		mergeS(&b);
		*headRef = sortedMerge(a, b);
	}
	void mergeSort() {
		mergeS(&begin);
	}
	~CFuncList() {
		begin->~CList();
	}
};