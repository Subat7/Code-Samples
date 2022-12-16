#ifndef SORTS_H
#define SORTS_H

#include <functional>
#include <iostream>
#include <vector>
#include <utility>


// Pretty printing for vectors of Printable objects (have ostream operator<< defined)
// Be careful: modifications risk failing tests
template <class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& container) {
    os << "[";
    bool first = false;
    for (const Printable& t : container) {
        if (first) {
            os << ", ";
        }
        if (typeid(t) == typeid(std::string)) {
            os << "\"" << t << "\"";
        } else {
            os << t;
        }
        first = true;
    }
    os << "]";
    return os;
}

// Selection sort (example of implementation expectations)
template <class Comparable>
void selection_sort(std::vector<Comparable>& container) {
    // print the initial container
    std::cout << container << std::endl;
    
    if (container.empty()) {
        return;
    }

    for (size_t index = 0; index < container.size()-1; index++) {
        // do 1 pass of selection sort: find the min and swap it to the front
        size_t index_min = index;
        for (size_t i = index+1; i < container.size(); i++) {
            if (container[i] < container[index_min]) {
                index_min = i;
            }
        }
        Comparable t = container[index];
        container[index] = container[index_min];
        container[index_min] = t;
        
        // print the container after each pass
        std::cout << container << std::endl;
    }
}

// TODO(student): implement 4 sorts from: insertion, shell, heap, merge, quick, bucket, radix

template <class Comparable>
void insertion_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;

    if (container.empty()) {
        return;
    }

    for (size_t p = 1; p < container.size(); ++p) {
        Comparable temp = std::move(container[p]);

        size_t j;
        for (j = p; j > 0 && temp < container[j - 1]; --j) {
            container[j] = std::move(container[j-1]);
        }
        container[j] = std::move(temp);

        std::cout << container << std::endl;
    }
}


size_t power(size_t base, size_t pow) {
    size_t ans = 1;
    for(size_t i = 0; i < pow; i++) {
        ans *= base;
    }
    return ans;
}


template <class Comparable>
void shell_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;
    if (container.empty()) {
        return;
    }

    size_t k = 0;
    while (power(2, k) < container.size()+1) {
        k++;
    }
    k--;

    size_t space = power(2, k) - 1;
    while (space > 0) {
        for(size_t i = space; i < container.size(); i++) {
            Comparable temp = container[i];
            size_t j = i;

            for( ; j>=space && temp < container[j - space]; j -= space) {
                container[j] = container[j-space];
            }

            container[j] = temp;
        }

        space /=2;
        std::cout << container << std::endl;
    }
}
template <class Comparable>
void heapify(std::vector<Comparable>& v) {
    v.insert(v.begin(), Comparable{});
    for(size_t i = v.size() / 2; i >0; i--) {
        Comparable h = v.at(i);
        size_t child;
        while(i*2 <= v.size()) {
            child = 2*i;
            if (child +1 < v.size() && v.at(child+1) < v.at(child)) {
                child++;
            } 
            if (child < v.size() && v.at(child)< v.at(i)) {
                std::swap(v.at(i), v.at(child));
            } else {
                break;
            }
            i = child;
        }
        v.at(i) = h;
    }
}

template <class Comparable>
Comparable heap_delete_min(std::vector<Comparable>& v) {
    if(v.size() <2) {
        throw std::invalid_argument("heap is empty, delete error");
    }
    size_t child, index =1;
    Comparable tmp = v.at(1);
    v.at(1) = v.at(v.size() - 1);
    v.pop_back();
    while(index*2 <= v.size()) {
        child = 2*index;
        if (child +1 < v.size() && v.at(child+1) < v.at(child)) {
            child++;
        } 
        if (child < v.size() && v.at(child)< v.at(index)) {
            std::swap(v.at(index), v.at(child));
        } else {
            break;
        }
        index = child;
    }
    return tmp;
}

template <class Comparable> 
void heap_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;
    if (container.empty()) {
        return;
    }

    std::vector<Comparable> v = container;

    heapify(v);

    container.clear();
    std::cout << v << std::endl;

    while(v.size()>1) {
        container.push_back(heap_delete_min(v));
        std::cout << v << std::endl;
        std::cout << container << std::endl;
    }
}

template <class Comparable> 
void merge_helper(std::vector<Comparable>& container, std::vector<Comparable>& v, size_t lhs, size_t rhs, size_t other) {
    size_t l = rhs - 1;
    size_t temp = lhs;
    size_t size = other - lhs + 1;

    while (lhs <= l && rhs <= other) {
        if (container.at(lhs) <= container.at(rhs)) {
            v.at(temp ++) = container.at(lhs++); 
        } else {
            v.at(temp++) = container.at(rhs++);
        }
    }

    while(lhs <= l) {
        v.at(temp ++) = container.at(lhs++);
    }

    while (rhs <= other) {
        v.at(temp ++) = container.at(rhs ++);
    }

    for(size_t i = 0; i < size; ++i) {
        container.at(other) = v.at(other);
        --other;
    }
}

template <class Comparable>
void merge_helper_2(std::vector<Comparable>& container, std::vector<Comparable>& v, size_t lhs, size_t rhs) {
    if (lhs < rhs) {
        size_t mid = (lhs + rhs) / 2;
        merge_helper_2(container, v, lhs, mid);
        merge_helper_2(container, v, mid+1, rhs);
        merge_helper(container, v, lhs, mid + 1, rhs);
        std::cout << container << std::endl;
    }
}


template <class Comparable> 
void merge_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;
    if (container.empty()) {
        return;
    }

    std::vector<Comparable> v(container.size());
    merge_helper_2(container, v, 0, container.size() - 1);

    //std::vector<Comparable> v(container.size());
   // mergesort(container, v, 0, container.size()-1);

}

template <class Comparable> 
void quick_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;
    if (container.empty()) {
        return;
    }
}


void bucket_sort(std::vector<unsigned int>& container) {
    std::cout << container << std::endl;
    if (container.empty()) {
        return;
    }

    size_t maximum = *(max_element(container.begin(), container.end() ));

    std::vector<unsigned int> v(maximum + 1);

    for (unsigned int i : container) {
        v[i] +=1;
    }

    std::cout << v << std::endl;

    container.clear();
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            for (unsigned int j = v[i]; j>0; j--) {
                container.push_back(i);
            }
            std::cout << container << std::endl;
        } 
    }

}

template <class Comparable>
void radix_sort(std::vector<Comparable> &container)
{
    std::cout << container << std::endl;

    if (container.empty())
    {
        return;
    }

    Comparable max = *(max_element(container.begin(), container.end()));

    unsigned maxdigits = digits(max);

    std::vector<std::vector<Comparable>> counter(10);

    size_t bigpower, power, index, count;
    for(size_t i = 0; i < maxdigits; ++i)
    {
        bigpower = power(10, i+1);
        power = power(10, i);

        for(size_t j = 0; j < container.size(); ++j)
        {
            Comparable temp = container.at(j) % bigpower;
            index = temp / power;
            counter.at(index).push_back(container.at(j));
        }
        
        for(std::vector v : counter)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        
        count = 0;

        for(size_t k = 0; k < 10; ++k)
        {
            while(!counter.at(k).empty())
            {
                container.at(count) = counter.at(k).front();
                counter.at(k).erase(counter.at(k).begin());
                count++;
            }
        }

        std::cout << container << std::endl;
    }
}

void radix_sort(std::vector<std::string> &container)
{
    std::cout << container << std::endl;

    if (container.empty())
    {
        return;
    }

    size_t maxlen = 0;
    for(std::string s : container)
    {
        if(s.length() > maxlen)
        {
            maxlen = s.length();
        }
    }

    std::vector<std::vector<std::string>> buckets(128);

    size_t count, index;
    for (int i = maxlen - 1; i >= 0; --i)
    {
        for (size_t j = 0; j < container.size(); ++j)
        {
            std::string temp = container.at(j);
            if(temp.length() > i)
            {
                index = int(temp.at(i));
            }
            else 
            {
                index = 0;
            }
            buckets.at(index).push_back(container.at(j));
        }

        for (std::vector v : buckets)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;

        count = 0;

        for (size_t k = 0; k < 128; ++k)
        {
            while (!buckets.at(k).empty())
            {
                container.at(count) = buckets.at(k).front();
                buckets.at(k).erase(buckets.at(k).begin());
                count++;
            }
        }

        std::cout << container << std::endl;
    }
}




#endif  // SORTS_H