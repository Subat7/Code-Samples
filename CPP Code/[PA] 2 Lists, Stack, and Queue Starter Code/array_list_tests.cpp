#include <iostream>
#include "array_list.h"
using namespace std;

int main() {
    // TODO(student): test your code
	ArrayList<int> list;

// insert 3 values at the end of the list
	list.insert(0, 1);
	list.insert(1, 2);
	list.insert(2, 3);

	cout << list[0] << list[1] << list[2] << endl;

// get the size
	cout << list.size() << endl;

// remove the middle element
	list.remove(1);
	cout << list[0] << list[1] << endl;
	cout << list.size() << endl;

	ArrayList<int> list2;
	list2 = list;
	list2.insert(0,7);
	cout << list2[0] << endl;

	// ArrayList<int> list3;
	// list3(list2);
	// cout << list3[0];



}
