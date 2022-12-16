#include "heap.h"

int main() {
    // TODO(student): write at least 1000 lines of test
	std::vector<int> heap{150,80,40,30,10,70,110,100,20,90,60,50,120,140,130};

	std::cout << "before heapify: ";
	for (int i : heap) { std::cout << i << " "; }
		std::cout << std::endl;

	heapify(&heap);

	std::cout << "after heapify: ";
	for (int i : heap) { std::cout << i << " "; }
		std::cout << std::endl;

	for (unsigned j = 0; j < 4; j++) {
		std::cout << "minimum is " << heap_get_min(heap) << std::endl;
		
		std::cout << "delete min" << std::endl;
		heap_delete_min(&heap);
		
		std::cout << "heap: ";
		for (int i : heap) { std::cout << i << " "; }
			std::cout << std::endl;
	}

	int values[] = {47,54,57,43,120,3};
	for (unsigned j = 0; j < 6; j++) {
		std::cout << "insert " << values[j] << std::endl;
		heap_insert(&heap, values[j]);

		std::cout << "heap: ";
		for (int i : heap) { std::cout << i << " "; }
			std::cout << std::endl;
	}

	
	return 0;
}
