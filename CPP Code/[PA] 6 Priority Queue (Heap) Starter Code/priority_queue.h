#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <functional>
#include <vector>
#include "heap.h"

template <class Comparable, class Container=std::vector<Comparable>, class Compare=std::less<typename Container::value_type>>
class PriorityQueue {
    Compare compare;
    Container container;

    size_t _size; 
    public:
    PriorityQueue() : compare(), container(), _size(0) {
    	const typename Container::value_type dfault{};
		container.insert(container.begin(), dfault);
    }

    explicit PriorityQueue(const Compare& cpe) : compare(cpe), container(std::vector<Comparable>()), _size(0) {
    	const typename Container::value_type dfault{};
		container.insert(container.begin(), dfault);
    }

    explicit PriorityQueue(const Container& c) : compare(std::less<typename Container::value_type>{}), container(c), _size(c.size()) {
    	heapify(container, compare);
    }


    PriorityQueue(const Compare& cpe, const Container& c) : compare(cpe), container(c), _size(c.size()) {
    	heapify(container, compare);
    }

    typename Container::const_reference top() const {
    	return heap_get_min(container);

    }

    bool empty() const {
    	return _size ==  0;
    }

    size_t size() const {
    	return _size;
    }

    void make_empty() {
    	container.clear();
    	_size = 0;
    	const typename Container::value_type dfault{};
		container.insert(container.begin(), dfault);

    }

    void push(const typename Container::value_type& data) {
    	heap_insert(container, data, compare);
    	_size++;
    }

    void pop() {
    	try {
    		heap_delete_min(container, compare);
    		_size--;
    	} 
    	catch (std::invalid_argument& err) {

    	}

    }

    void print_queue( std::ostream& os = std::cout) const {
    	if(empty()) {
    		os << "<empty>\n" ;

    	} else {
    		for (size_t i = 1; i < _size; i++) {
    			os << container[i] << ", ";

    		}
    		os << container[_size] << "\n";

    	}
    } 







    // TODO(student): implement PriorityQueue
};

#endif  // PRIORITY_QUEUE_H