#include "hashtable_open_addressing.h"

int main() {
    // TODO(student): write at least 1000 lines of test

    HashTable<int> other;
    other.print_table();
    other.insert(3);
    other.insert(5);
    size_t n = 1000;
    size_t i = 1;
    while(other.size() < n) {
    	other.insert(i);
    	i++;
    }   
    other.print_table();

    other.insert(3);

    other.remove(3);
    other.insert(3);
    other.remove(20000);




    
    return 0;
}