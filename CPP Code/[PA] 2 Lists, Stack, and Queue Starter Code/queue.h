#ifndef QUEUE_H
#define QUEUE_H
#include <cstddef>
#include <iostream>
#include "array_list.h"
using namespace std;

template <typename Object>
class Queue : public ArrayList<Object>{
    // TODO(student): implement Queue
	ArrayList<Object> list;

public:
	Queue():list(ArrayList<Object>()) {}
	Queue(const Queue& other) : list(other.list) {}
	~Queue() {}
	Queue& operator=(const Queue& other) {
		this->list = other.list;
		return *this;
	}
	void enqueue(const Object& value) {
		list.insert(list.size(), value);
	}
	Object dequeue() {
		if (list.size() == 0) {
			throw out_of_range("dequeue out of range");
		}
		Object n = list[0];
		list.remove(0);
		return n;
	}
	Object& front() {
		if (list.size() == 0) {
			throw out_of_range("front out of range");
		} 
		return list[0];
	}
};

#endif  // QUEUE_H
