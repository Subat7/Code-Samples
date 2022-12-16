#include "array_list.h"
#include "doubly_linked_list.h"
#include "stack.h"
#include "queue.h"

int main() {
    {
        ArrayList<int> list;
        list.size();
        list.insert(0, 0);
        list.operator[](0);
        list.remove(0);
    }
    
    {
        ArrayList<char*> list;
        list.size();
        list.insert(0, new char[1]{'\0'});
        list.operator[](0);
        {
            ArrayList<char*> copy = list;
            copy.remove(0);
            copy = list;
        }
        list.remove(0);
    }
    
    {
        DoublyLinkedList<int> list;
        list.size();
        list.insert(0, 0);
        list.operator[](0);
        list.remove(0);
    }
    
    {
        DoublyLinkedList<char*> list;
        list.size();
        list.insert(0, new char[1]{'\0'});
        list.operator[](0);
        {
            DoublyLinkedList<char*> copy = list;
            copy.remove(0);
            copy = list;
        }
        list.remove(0);
    }
    
    {
        Stack<int> stack;
        stack.push(0);
        stack.top();
        stack.pop();
    }
    
    {
        Stack<char*> stack;
        stack.push(new char[1]{'\0'});
        stack.top();
        {
            Stack<char*> copy = stack;
            copy.pop();
            copy = stack;
        }
        stack.pop();
    }
    
    {
        Queue<int> queue;
        queue.enqueue(0);
        queue.front();
        queue.dequeue();
    }
    
    {
        Queue<char*> queue;
        queue.enqueue(new char[1]{'\0'});
        queue.front();
        {
            Queue<char*> copy = queue;
            copy.dequeue();
            copy = queue;
        }
        queue.dequeue();
    }
}
