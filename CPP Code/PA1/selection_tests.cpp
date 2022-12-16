#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "selection.h" 

using namespace std;

int main() {
	const int* list1 = nullptr;
	int arr[7] = {8, 6, 7, 5, 3, 0, 9};
	const int* list2 = arr;
	//const int* list2[4] = {1,2,3,4};
	cout << select(2, list2, 7) << endl;
	cout << select(1, list2, 7) << endl;
	cout << select(7, list2, 7) << endl;
	//cout << select(2, list1, 7) << endl;
	try {
		select(0, list2, 7);
	}
	catch (const std::invalid_argument& err) {
		cout<< "Catched" << err.what() << endl;
	}

	try {
		select(2, list1, 7);
	}
	catch (const std::invalid_argument& err) {
		cout<< "Catched" << err.what() << endl;
	}
	try {
		select(8, list2, 7);
	}
	catch (const std::invalid_argument& err) {
		cout<< "Catched" << err.what() << endl;
	}
	// cout << select(0, list2, 7) << endl;
	// cout << select(8, list2, 7) << endl;
	//cout << select(2, list2, 4) << endl;
}