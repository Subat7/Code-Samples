#ifndef HEAP_H
#define HEAP_H
#include <deque>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::cout, std::endl, std::vector;

// TODO(student): implement heap functions

template <class Container, class Compare=std::less<typename Container::value_type>>
void heapify(Container* c_ptr, Compare cpe =std::less<typename Container::value_type>{}) {
	const typename Container::value_type dfault{};
	c_ptr->insert(c_ptr->begin(), dfault);
	for(size_t i = c_ptr->size() / 2; i >0; i--) {
		const typename Container::value_type temp = c_ptr->at(i);
		size_t child, j = i;
		while(j*2 <= c_ptr->size()) {
			child = 2*j;
			if (child +1 < c_ptr->size() && cpe(c_ptr->at(child+1), c_ptr->at(child))) {
				child++;
			} 
			if (child < c_ptr->size() && cpe(c_ptr->at(child), c_ptr->at(j))) {
				std::swap(c_ptr->at(j), c_ptr->at(child));
			} else {
				break;
			}
			j = child;
		}
		c_ptr->at(j) = temp;
	}

}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heapify(Container& c, Compare cpe =std::less<typename Container::value_type>{}) {
	heapify(&c, cpe);
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_insert(Container* c_ptr, const typename Container::value_type& data, Compare cpe =std::less<typename Container::value_type>{}) {
	if(c_ptr->empty()) {
		const typename Container::value_type dfault{};
		c_ptr->insert(c_ptr->begin(), dfault);
	}
	c_ptr->push_back(data);
	size_t index = c_ptr->size() - 1;
	while (index>1 && cpe(c_ptr->at(index), c_ptr->at(index/2))) {
		std::swap(c_ptr->at(index), c_ptr->at(index/2));
		index /=2;
	}
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_insert(Container& c, const typename Container::value_type& data, Compare cpe =std::less<typename Container::value_type>{}) {
	heap_insert(&c, data, cpe);
}


template <class Container>
const typename Container::value_type& heap_get_min(const Container& c) {
	if(c.size() < 2) {
		throw std::invalid_argument("heap is empty");
	}
	return c.at(1);
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_delete_min(Container* c_ptr, Compare cpe =std::less<typename Container::value_type>{}) {
	if(c_ptr->size() <=1) {
		throw std::invalid_argument("heap is empty, delete error");
	}
	size_t child, index =1;
	c_ptr->at(1) = c_ptr->at(c_ptr->size()-1);
	c_ptr->pop_back();

	while(index*2 <= c_ptr->size()) {
		child = 2*index;
		if (child +1 < c_ptr->size() && cpe(c_ptr->at(child+1), c_ptr->at(child))) {
			child++;
		} 
		if (child < c_ptr->size() && cpe(c_ptr->at(child), c_ptr->at(index))) {
			std::swap(c_ptr->at(index), c_ptr->at(child));
		} else {
			break;
		}
		index = child;
	}

}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_delete_min(Container& c, Compare cpe =std::less<typename Container::value_type>{}) {
	heap_delete_min(&c, cpe);
}








#endif  // HEAP_H