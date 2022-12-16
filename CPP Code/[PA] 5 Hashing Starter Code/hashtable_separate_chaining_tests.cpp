#include "hashtable_separate_chaining.h"
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::vector, std::cout, std::cin, std::endl, std::list;

int main() {
    // TODO(student): write at least 1000 lines of test
    HashTable<int> other;
    other.insert(3);
    other.insert(5);
    size_t n = 1000;
    size_t i = 1;
    while(other.size() < n) {
    	other.insert(i);
    	i++;
    }   
    other.print_table();

    
    
    return 0;
}
