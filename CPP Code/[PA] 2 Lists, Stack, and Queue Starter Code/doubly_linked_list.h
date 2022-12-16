#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>
#include <iostream>
using namespace std;

template <typename Object>
struct Node {
	Object data;
	Node* next;
	Node* prev; 
};

template <typename Object>
class DoublyLinkedList {
    // TODO(student): implement DoublyLinkedList
    Node<Object>* headPtr;
    Node<Object>* tailPtr;
    Node<Object>* currentPtr;
    size_t sizeNum;

public:
	DoublyLinkedList() : headPtr(nullptr), tailPtr(nullptr), currentPtr(nullptr), sizeNum(0) {}

	DoublyLinkedList(const DoublyLinkedList& other) : headPtr{nullptr}, tailPtr(nullptr),currentPtr(nullptr), sizeNum(0) {
		currentPtr = other.headPtr;
		while (currentPtr != nullptr) {
			insert(sizeNum, currentPtr->data);
			currentPtr = currentPtr->next;
		}
	}

	~DoublyLinkedList() {
		while(this->sizeNum > 0) {
			currentPtr = headPtr->next;
			delete this->headPtr;
			this->headPtr=currentPtr;
			this->sizeNum--;
		}
	}

	DoublyLinkedList& operator=(const DoublyLinkedList& other) {
		if (this == &other) {
			return *this;
		}
		if (other.headPtr == nullptr) {
			this->headPtr = nullptr;
			this->tailPtr = nullptr;
			this->sizeNum = 0;
		}
		while (sizeNum > 0) {
			currentPtr = headPtr->next;
			delete this->headPtr;
			this->headPtr=currentPtr;
			this->sizeNum--;
		}

		currentPtr = other.headPtr;
		while (currentPtr != nullptr) {
			insert(sizeNum, currentPtr->data);
			currentPtr = currentPtr->next;
		}
		this->sizeNum = other.sizeNum;
		return *this;
	}

	size_t size() const {return this->sizeNum;}

	Object& operator[](size_t index) {
		if (index >= this->sizeNum) {
			throw out_of_range("Operator[] access out of bounds");
		}
		currentPtr = this->headPtr;
		for (size_t i = 0; i < index; i++) {
			currentPtr = currentPtr->next;
		}
		return currentPtr->data;
	}

	void insert(size_t index, const Object& value) {
		if (index > this->sizeNum) {
			throw out_of_range("insert index out of bounds");
		} else if (index == 0) {
			if (sizeNum == 0) {
				Node<Object>* n = new Node<Object>;
				this->sizeNum++;
				n->next = nullptr;
				n->prev = nullptr;
				n->data = value;
				this->headPtr = n;
				this->tailPtr = n;
			} else {
				Node<Object>* n = new Node<Object>;
				this->sizeNum++;
				n->next = this->headPtr;
				this->headPtr->prev = n;
				n->prev = nullptr;
				n->data = value;
				this->headPtr = n;
			}
		} else if (index == this->sizeNum) {
			Node<Object>* n = new Node<Object>;
			this->sizeNum++;
			n->next = nullptr;
			n->prev = this->tailPtr;
			this->tailPtr->next = n;
			n->data = value;
			this->tailPtr = n; 
		} else {
			Node<Object>* n = new Node<Object>;
			currentPtr = this->headPtr;
			for (size_t i = 0; i < index; i++) {
				currentPtr = currentPtr->next;
			}
			n->data	= value;
			n->next = currentPtr;
			n->prev = currentPtr->prev;
			currentPtr->prev = n;
			currentPtr = n;
			currentPtr->prev->next = n;
			this->sizeNum++;
		}
	}

	void remove(size_t index) {
		if (index >= this->sizeNum) {
			throw out_of_range("Remove out of bounds");
		}
		currentPtr = this->headPtr;
		for (size_t i = 0; i < index; i++) {
			currentPtr = currentPtr->next;
		}
		if (currentPtr == headPtr) {
			this->headPtr = currentPtr->next;
		} 
		if (currentPtr == tailPtr) {
			this->tailPtr = currentPtr->prev;
		} 
		if (currentPtr->prev != nullptr) {
			currentPtr->prev->next = currentPtr->next;
		}
		if (currentPtr->next != nullptr) {
			currentPtr->next->prev = currentPtr->prev;
		}
		delete currentPtr;
		sizeNum--;
	} 

};

#endif  // DOUBLY_LINKED_LIST_H
