#ifndef STACK_H
#define STACK_H
#include <cstddef>
#include <iostream>
#include "array_list.h"
using namespace std;

template <typename Object>
class Stack : public ArrayList<Object>{
   // TODO(student): implement Stack
	ArrayList<Object> list;
public:
	Stack(): list(ArrayList<Object>()) {}
	Stack(const Stack& other) : list(other.list) {}
	~Stack() {}
	Stack& operator=(const Stack& other) {
		this->list = other.list;
		return *this;
	} 
	void push(const Object& value) {
		list.insert(list.size(), value);
	}
	void pop() {
		if (list.size() == 0) {
			throw out_of_range("list is empty to pop");
		}
		list.remove(list.size() - 1);
	}
	Object& top() {
		if (list.size() == 0) {
			throw out_of_range("list is empty to top");
		}
		return list[list.size() - 1];
	}

};

#endif  // STACK_H