#pragma once
#include<iostream>

using std::cout;
using std::endl;

template<typename T>
class List
{
private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T>* head;

public:
	List();

	void pushBack(T data);
	int getsize();
	T& operator[](const int index);
	void popFront();
	void pushFront(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void clear();
	void insertionSort();
};

template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::pushBack(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	size++;
}

template<typename T>
inline int List<T>::getsize() {
	return size;
}

template<typename T>
T& List<T>::operator[](const int index) {
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::popFront() {
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void List<T>::pushFront(T data) {
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		pushFront(data);
	}
	else {
		Node<T>* prev = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}

		Node<T>* newNode = new Node<T>(data, prev->pNext);

		prev->pNext = newNode;

		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		popFront();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		popFront();
	}
}

template< typename T> 
void List<T>::insertionSort(){
	if(head==nullptr) return;
	Node<T>* start=head;
	Node<T>* end=head;
	Node<T>* key=head->pNext;
	Node<T>* temp=nullptr;
	Node<T>* tStart=nullptr;
	Node<T>* tEnd=nullptr;
	Node<T>* Next;	
	while(key!=nullptr){
		Next=key->pNext;
		if(end->data <= key->data)
		{
			 end=key;
			 key=Next;	
			 continue;
		};
		if(key->data <= start->data)
		{
			end->pNext=key->pNext;
			temp=start;
			start=key;
			start->pNext=temp;
			key=Next;
			continue;	
		};
		for(temp=start; temp!=end; temp=temp->pNext ){
			if( temp->data < key->data  &&  key->data <= temp->pNext->data)
			{
				end->pNext=key->pNext;
				tStart=temp->pNext;
				temp->pNext=key;
				key->pNext=tStart;
				break;
			};		
		
		};
		key=Next;
	};
	head=start;
 };
