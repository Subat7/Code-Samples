#include <iostream>
#include <cstddef> 
#include <stdexcept> 
#include "collection.h"
using namespace std;

int main() {
	Collection<int> test;

	cout << test.size() << endl;
	cout << test.is_empty() << endl;

	test.insert(1);
	test.insert(2);
	test.insert(3);
	test.insert(4);

	cout << test.size() << endl;
	cout << test.is_empty() << endl;
	cout << test.contains(4) << endl;
	cout << test.contains(5) << endl;
	test.remove(2);
	cout << test.size() << endl;
	test.make_empty();
	cout << test.is_empty() << endl;

	Collection<int> test2;
	test2 = test;
	

}