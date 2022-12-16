#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

int main() {
    // TODO(student): test your code
   // make an empty list
	DoublyLinkedList<int> list;
	try {
		list.remove(1);
	} catch (const out_of_range& ) {
		cout << "catched" << endl;
	};
	try  {
		list[1];
	} catch (const out_of_range& ) {
		cout << "catched" << endl;
	}



// insert 3 values at the end of the list
	list.insert(0, 1);
	list.insert(1, 2);
	list.insert(2, 3);
	list.insert(3, 4);
	list = list;

	DoublyLinkedList<int> list1;
	list1 = list;

	DoublyLinkedList<int> list2(list);
	list2.remove(1);
	cout << list[0] << list[1] << list[2] << endl;

	DoublyLinkedList<int> list3;
	DoublyLinkedList<int> list4;
	list4 = list3;

	cout <<	list3.size() << endl;

	try {
		list3.insert(5, 5);
	} catch (const out_of_range& ) {
		cout<< "catched insert out of range" << endl;
	}

	list3.insert(0,1);
	list3.insert(0,3);
	list3.insert(list3.size(),3);
	list3.insert(1,3);
	list3.remove(list3.size()-1);
	list3.remove(list3.size()-1);
	list3.remove(list3.size()-1);
	cout << list3.size() << endl;
	list3.remove(0);

	list4 = list4;
	list4 = list3;





// get the size
	size_t size = list.size();
	cout << list[0] << list[1] << list[2] << list[3] << endl;
	cout << size << endl;
	list.remove(3);

	size = list.size();
	cout << list[0] << list[1] << list[2] << endl;
	cout << size << endl;

// remove the middle element
	list.remove(1);

// access the element at index 1
	int value = list[1];
	cout << list[0] << value << endl;
	cout << list.size() <<endl;

	list.remove(0);
	value = list[0];
	cout << value << endl;
	cout << list.size() <<endl;




}