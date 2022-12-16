#ifndef COLLECTION_H
#define COLLECTION_H

#include <cstddef>

template <typename Object>
class Collection {
    // TODO(student): the rest of the template
    Object* array;
    size_t sizeNum;
public:
	Collection() : array(nullptr), sizeNum(0) {}
	Collection(const Collection& other) : array(other.array), sizeNum(other.sizeNum) {}
	Collection& operator=(const Collection& other) {
		if (this == &other) {
			return *this;
		} else {
			this->sizeNum = other.sizeNum;
			this->array = new Object[this->sizeNum];
			for (size_t i = 0; i < this->sizeNum; i++) {
				this->array[i] = other.array[i];
			}
		}
		return *this;
	}
	~Collection() {
		delete [] this->array;
	}

	size_t size() const {
		return this->sizeNum;
	}

	bool is_empty() const {
		if (this->sizeNum == 0) {
			return true;
		} else {
			return false;
		}
	}

	void make_empty() {
		this->sizeNum = 0;
		delete [] this->array;
		this->array = new Object[0];
	}

	void insert(const Object& obj) {
		this->sizeNum = sizeNum + 1;
		Object* temp = new Object[sizeNum];
		for (size_t i = 0; i < this->sizeNum; i++) {
			if (i == sizeNum - 1) {
				temp[i] = obj;
			} else {
				temp[i] = this->array[i];
			}
		}
		delete [] this->array;
		this->array = temp;
	}

	void remove(const Object& obj) {
		Object* temp = new Object[sizeNum - 1];
		bool removed = false;
		for (size_t i = 0; i < this->sizeNum; i++) {
			if ((this->array[i] == obj) & (removed == false)) {
				removed = true;
				continue;
			} else if (removed == false) {
				temp[i] = this->array[i];
			} else if (removed == true) {
				temp[i - 1] = this->array[i];
			}
		} 
		this->sizeNum--;
		delete [] this->array;
		this->array = temp;
	}

	bool contains(const Object& obj) const {
		for (size_t i = 0; i < this->sizeNum; i++) {
			if (this->array[i] == obj) {
				return true;
			}
		}
		return false;
	}
};

#endif  // COLLECTION_H