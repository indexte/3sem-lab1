#pragma once

template<typename T>
class List
{
public:
	List();

	void pushBack(T data);
	int getSize();
	T& operator[](const int index);
	void popFront();
	void pushFront(T data);
	void insert(T data, int index);
	void removeAt(int index);

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
inline int List<T>::getSize() {
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
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

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