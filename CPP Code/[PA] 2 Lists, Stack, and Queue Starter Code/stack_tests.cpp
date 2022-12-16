#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    // TODO(student): test your code
    // make an empty stack
	Stack<int> stack;

	try {
		stack.pop();
	} catch (const out_of_range& ) {
		cout << "catched" << endl;
	}


// push 3 values onto the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);

// remove the top element
	stack.pop();

// access the top element
	int value = stack.top();
	cout << value << endl;

	Stack<int> stack1;
	stack1 = stack;
	stack1 = stack1;

}
