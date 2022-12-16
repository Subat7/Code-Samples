#ifndef HASHTABLE_OPEN_ADDRESSING_H
#define HASHTABLE_OPEN_ADDRESSING_H
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::vector, std::cout, std::cin, std::endl, std::list;

enum state {empty, deleted, active};

template <class Key, class Hash=std::hash<Key>>
class HashTable {

	struct node
	{
		Key key;
		state S;

		node() : key(Key{}), S(empty) {};

		void init(Key k) {
			key = k;
			S = active;
		}

	};

	bool isPrime(size_t num) {
		if(num == 3)  {
			return true;
		} 
		if (num % 3 == 0 || num % 7 == 0 || num == 1) {
			return false;
		}
		return true;
	}

	size_t next_Prime(size_t num) {
    	size_t temp = (2 * num) + 1;
    	while (!isPrime(temp)) {
    		temp += 2;
    	}
    	return temp;
    }
    // TODO(student): implement an open addressing hash table

	vector<node> v;
	size_t _size;
	size_t active_size;

public:
	HashTable() : v(11, node()), _size(0), active_size(0) {}

	explicit HashTable(size_t nodes) : v(nodes, node()), _size(0), active_size(0) {}

	bool is_empty() const {
		return active_size == 0;
	}

	size_t size() const {
		return active_size;
	}

	size_t table_size() const {
		return this->v.size();
	}

	void make_empty() {
		v = vector<node>(table_size(), node());
		_size = 0;
		active_size = 0;
	}

	bool insert(const Key& k) {
		size_t hash_value = position(k);
		if(this->v.at(hash_value).key == k && this->v.at(hash_value).S == active) {
			return false;
		} else if (this->v.at(hash_value).key == k && this->v.at(hash_value).S == deleted) {
			this->v.at(hash_value).S = active;
			this->active_size++;
			return true;
		} 
		this->v.at(hash_value).init(k);
		this->_size++;
		this->active_size++;

		if(load_factor() > 0.5) {
			rehash(next_Prime(table_size()));

		}
		return true;
	}

	size_t remove(const Key& k) {
		size_t hash_value = position(k);
		if (contains(k)) {
			active_size--;
			v.at(hash_value).S = deleted;
			return 1;
		}
		return 0;
	}

	bool contains(const Key& k) {
		size_t hash_value = position(k);
		if (v.at(hash_value).key ==  k && v.at(hash_value).S == active) {
			return true;
		}
		return false;
	}

	size_t position(const Key& k) const {
		size_t hash_value = Hash{}(k);
		hash_value = hash_value % table_size();
		while(v.at(hash_value).S == active || v.at(hash_value).S == deleted) {
			if(v.at(hash_value).key == k) {
				return hash_value;
			}
			hash_value++;
			hash_value = hash_value % table_size();

		}
		return hash_value;
	}

	float load_factor() {
		return (float)this->_size / table_size();
	}

	void rehash(size_t nodes) {
 		if (nodes == table_size()) {
 			return;
 		}
 		if (((float)active_size / nodes) > 0.5) {
 			nodes = (size_t)(((float)active_size / 0.5));
 		}
 		vector<node> temp = this->v;
 		this->v = vector<node>(nodes, node());
 		this->_size = 0;
 		this->active_size = 0;
 		for (node n : temp) {
 			if (n.S == active) {
 				insert(n.key);
 			}
 		}

 	}

 	void print_table(std::ostream& os = std::cout ) {
 		if (is_empty()) {
 			os << "<empty>\n" ;
 		} else {
 			size_t count = 0;
 			for (node N : v) {
 				if (N.S == active) {
 					os << count << " : " << N.key << "\n" ;
 				}
 				count++;
 				
 			}

 		}
 	}



};

#endif  // HASHTABLE_OPEN_ADDRESSING_H