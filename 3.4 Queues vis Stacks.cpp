/******************************************************************************
Queue via Stacks
Implement a MyQueue class which implements a queue using two stacks.
*******************************************************************************/
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
    
    stack<int> newStack;
    stack<int> oldStack;
    
    public:
    MyQueue() {}
    
    // queue is empty? O(1)
    bool isEmpty(){
        return newStack.empty() && oldStack.empty();
    }
    
    // queue size O(1)
    int size(){
        return newStack.size() + oldStack.size();
    }
	
	// shift elements from newStack to oldStack O(N)
	void shiftStacks(){
		if(oldStack.empty()){
			while(!newStack.empty()){
				oldStack.push(newStack.top());
				newStack.pop();
			}
		}
	}
    
    // pop front element O(N)
    void popFront() { 
		shiftStacks();
		oldStack.pop();
    }
    
    // return peek element O(N)
    int front(){
		shiftStacks();
		return oldStack.top();
    }
    
    // push new element to the back O(1)
    void pushBack(int item){
		newStack.push(item);
    }
	
};


int main()
{
    MyQueue queue;
    queue.pushBack(5);
    queue.pushBack(1);
    queue.pushBack(3);
    queue.pushBack(2);

    cout << queue.front() << endl;
    cout << queue.size() << endl;
    cout << queue.isEmpty() << endl;
    queue.popFront();
    cout << queue.front() << endl;

    return 0;
}
