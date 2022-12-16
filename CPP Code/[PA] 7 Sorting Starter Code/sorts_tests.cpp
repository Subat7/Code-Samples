#include "sorts.h"
#include <functional>
#include <iostream>
#include <vector>
#include <utility>


int main() {
 //    // TODO(student): write tests

   

    {
    	std::vector<unsigned int> v = {8,1,9,4,1,1,9,6,1,2,3,5,1,7,9,5,2,8,5,8,4,1,7,5,1,5};

    	bucket_sort(v);
	}

	{
		std::vector<int> numbers = {81,94,11,96,12,35,17,95,28,58,41,75,15};
		insertion_sort(numbers);
	}

	{
		std::vector<int> numbers = {81,94,11,96,12,35,17,95,28,58,41,75,15};
		shell_sort(numbers);
	}

	{
		std::vector<int> numbers = {81,94,11,96,12,35,17,95,28,58,41,75,15};
		heap_sort(numbers);
	}

	{
		std::vector<int> numbers = {81,94,11,96,12,35,17,95,28,58,41,75,15};
		merge_sort(numbers);
	}

	{
		std::vector<int> numbers;
		quick_sort(numbers);
	}

	{
		std::vector<int> numbers;
		radix_sort(numbers);
		std::vector<std::string> number;
		radix_sort(number);
	}


    
    return 0;
}
