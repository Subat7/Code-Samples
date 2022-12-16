#ifndef HASHTABLE_SEPARATE_CHAINING_H
#define HASHTABLE_SEPARATE_CHAINING_H
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::vector, std::cout, std::cin, std::endl, std::list;

template <class Key, class Hash=std::hash<Key>>
class HashTable {
    // TODO(student): implement a separate chaining hash table
    vector<list<Key>> v_other;
    size_t size_other;
    float max_other;

    

public:
	HashTable() : v_other(11, list<Key>()), size_other(0), max_other(1) {}

	explicit HashTable(size_t other) : v_other(other, list<Key>()), size_other(0), max_other(1) {}

	bool is_empty() const {
		return size_other == 0;
	}

	bool isPrime(size_t other) {
		if(other == 3)  {
			return true;
		} 
		if (other % 3 == 0 || other % 7 == 0 || other == 1) {
			return false;
		}
		return true;
	}

	size_t next_Prime_other(size_t other) {
    	size_t temp_other_other = (2 * other) + 1;
    	while (!isPrime(temp_other_other)) {
    		temp_other_other += 2;
    	}
    	return temp_other_other;
    }

	size_t size() {return size_other;}

	void make_empty() {
		v_other = vector<list<Key>>(bucket_count(), list<Key>());
		size_other = 0;
	}

	bool insert(const Key& other) {
		if (!contains(other)) {
			this->v_other.at(bucket(other)).push_back(other);
			this->size_other++;
			if(load_factor() > this->max_other) {
				rehash(next_Prime_other(bucket_count()));
			}
			return true;
		}
		return false;
	}

 	size_t remove(const Key& other) {
 		if (contains(other)) {
			this->v_other.at(bucket(other)).remove(other);
			this->size_other--;
			return 1;
		}
		return 0;
 	}

 	bool contains(const Key& other) {
 		list<Key> other_list = v_other.at(bucket(other));
 		for (Key k : other_list) {
 			if (other == k) {
 				return true;
 			}
 		}
 		return false;
 	}

 	size_t bucket_count() const {
 		return v_other.size();
 	}

 	size_t bucket_size(size_t other) {
 		if(other >= v_other.size()) {
 			throw std::out_of_range("Other index is wrong other other I lvoe other, I have sex with other");
 		}
 		return v_other.at(other).size();
 	}

 	size_t bucket(const Key& other) const {
 		size_t hash_val_other = Hash{}(other);
 		return hash_val_other % bucket_count();
 	}

 	float load_factor() const {
 		return (float)this->size_other / bucket_count();          
 	}

 	float max_load_factor() const {
 		return max_other;
 	}

 	void max_load_factor(float other) {
 		if (other <= 0) {
 			throw std::invalid_argument("Other other otheer other I love other");
 		}
 		this->max_other = other;
 		if (load_factor() > other) {
 			rehash(next_Prime_other(bucket_count()));
 		}
 	}

 	void rehash(size_t other) {
 		if (other == bucket_count()) {
 			return;
 		}
 		if (((float)size_other / other) > max_load_factor()) {
 			other = (size_t)((float)size_other / max_load_factor());
 		}
 		vector<list<Key>> temp_other = this->v_other;
 		this->v_other = vector<list<Key>>(other, list<Key>());
 		this->size_other = 0;
 		for (list<Key> l : temp_other) {
 			for (Key k : l) {
 				insert(k);
 			}
 		}
 	}

 	void print_table(std::ostream& os = std::cout ) {
 		if (is_empty()) {
 			os << "<empty>\n" ;
 		} else {
 			size_t count = 0;
 			for (list<Key> l : v_other) {
 				if (!l.empty()) {
 					os << count << " :" ;
 					for(Key k : l) {
 						os << k << " , ";
 					}
 					os << "\n" ;
 				}
 				count++;
 			}

 		}
 	}

};



#endif  // HASHTABLE_SEPARATE_CHAINING_H