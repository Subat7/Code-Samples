#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    // TODO(student): test your code
    // make an empty queue
	Queue<int> queue;
	try {
		queue.front();
	} catch (const out_of_range& ) {
		cout << "catched" << endl;
	}

// enqueue 3 values into the queue
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);

// remove the front element
	queue.dequeue();

// access the front element
	int value = queue.front();
	cout << value << endl;

	Queue<int> queue1;
	queue1 = queue;
	queue1 = queue1;


}
