/******************************************************************************
Queue via Stacks
Implement a MyQueue class which implements a queue using two stacks.
*******************************************************************************/
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
    
    stack<int> mainStack;
    stack<int> auxStack;
    
    // shift elements from stack src to stack dest
    static void reverseStack(stack<int>& src, stack<int>& dest){
        while(src.empty() == false){
            dest.push(src.top());
            src.pop();
        }
    }
    
    public:
    MyQueue() {}
    
    // queue is empty?
    bool isEmpty(){
        return mainStack.empty();
    }
    
    // queue size
    int size(){
        return mainStack.size();
    }
    
    // pop front element
    void popFront() {
        if(mainStack.empty()){
            throw "Queue is empty!";
        }
        // reverse elements to auxStack
        reverseStack(mainStack, auxStack);
        
        // pop the oldest
        auxStack.pop();
        
        // reverse back to mainStack
        reverseStack(auxStack,mainStack);
    }
    
    // return peek element
    int front(){
        if(mainStack.empty()){
            throw "Queue is empty!";
        }
        // reverse elements to auxStack
        reverseStack(mainStack, auxStack);
       
        // save the oldest
        int peek = auxStack.top();
        
        // reverse back to mainStack
        reverseStack(auxStack, mainStack);
        return peek;
    }
    
    // push new element to the back
    void pushBack(int item){
        mainStack.push(item);
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

    return 0;
}
