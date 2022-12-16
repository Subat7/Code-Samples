#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "selection.h" 

using namespace std;


int select(size_t k, const int* list, size_t N) {
	if (list == nullptr) {
		throw invalid_argument("List is a null pointer");
	}
	if (k > N || k <= 0) {
		throw invalid_argument("k is out of bound");
	}
	int max;
	int temp_max = list[0];
	for (size_t j = 0; j < k; ++j) {
  		for (size_t i = 0; i < N;  ++i)
		{
			if (j == 0) {
				if (list[i] > temp_max) {
					temp_max = list[i];
				}
			} else {
				if ((list[i] > temp_max) & (list[i] < max)) {
					temp_max = list[i];
				}
			}
		}
		max = temp_max;
		temp_max = -INT32_MAX;
	}
	return max;
}

// int main() {
// 	const int list[7] = {-8,6,7,5,3,0,-9};

// 	cout << select(7, list, 7);
// }