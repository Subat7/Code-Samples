#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <cstddef>
#include <iostream>

using std::cout, std::endl;

template <typename Object>
class ArrayList
{
protected:
    size_t _size;
    size_t cap;
    Object *arr;

public:
    ArrayList() : _size(0), cap(1), arr(new Object[1]){};

    explicit ArrayList(size_t size) : _size(0), cap(size), arr(new Object[this->cap]){};

    ArrayList(const ArrayList& other) : _size(other._size), cap(other.cap), arr(nullptr) {
    	this->arr = new Object[this->cap];
    	for (unsigned int i = 0; i < this->_size; i++) {
    		this->arr[i] = other.arr[i];
    	}
    } 

    ~ArrayList() { delete[] this->arr; };

    ArrayList &operator=(const ArrayList &rhs)
    {
        if (this != &rhs)
        {
            this->_size = rhs._size;
            this->cap = rhs.cap;
            delete [] arr;
            this->arr = new Object[cap];
            for (unsigned int i = 0; i < this->_size; i++)
            {
                arr[i] = rhs.arr[i];
            }
        }
        return *this;
    }

    size_t size() const { return this->_size; };

    Object &operator[](size_t pos)
    {
        if (pos >= this->_size)
        {
            throw std::out_of_range("The position is not in range ([] operator).");
        }

        return arr[pos];
    }

    void insert(size_t pos, const Object &obj)
    {
        if (pos > this->_size)
        {
            throw std::out_of_range("The insert position is not in range.");
        }

        if (this->_size == this->cap)
        {
            this->cap *= 2;
            Object *newarr = new Object[cap];
            for (unsigned int i = 0; i < _size; i++)
            {
                newarr[i] = this->arr[i];
            }
            delete[] this->arr;
            this->arr = newarr;
        }

        for (unsigned int i = this->_size; i > pos; i--)
        {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[pos] = obj;
        this->_size++;
    }

    void remove(size_t pos)
    {
        if (pos >= this->_size)
        {
            throw std::out_of_range("The remove position is not in range.");
        }

        for (unsigned int i = pos; i < this->_size - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->_size--;
    }
};

#endif // ARRAY_LIST_H