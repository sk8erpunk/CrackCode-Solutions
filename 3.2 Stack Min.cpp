/******************************************************************************
Stack Min 
How would you design a stack which, in addition to push and pop, has a function 
min which returns the minimum element? Push, pop and min should all operate in
O(1) time.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MyStack {
    
    stack<int> myStack;     // holds items
    stack<int> minStack;    // holds current minimum 
    
    public: 
    MyStack(){} 
    
    // Pushes item to MyStack
    // Pushes Min(item,minStack.top()) to minStack
    void push(int item){
        myStack.push(item);
        if(!minStack.empty()){
            minStack.push(min(item,minStack.top()));
        } else {
            minStack.push(item);
        }
    }
    
    // Pop elements from both stacks 
    void pop(){
        if(myStack.empty()){
            throw "Stack is empty!";
        }
        myStack.pop();
        minStack.pop();
    }
    
    // Return current minimum
    int getMin(){
        if(minStack.empty()){
            throw "stack is empty";
        }
        return minStack.top();
    }
}; 
int main()
{
    MyStack s;
    s.push(14);
    s.push(18);
    s.push(33);
    s.push(5);
    s.push(4);
    s.push(13);
    s.push(1);
    cout << s.getMin() << " " << endl;
    s.pop();
    cout << s.getMin() << " " << endl;
    s.pop();
    cout << s.getMin() << " " << endl;
    s.pop();
    cout << s.getMin() << " " << endl;
    s.pop();
    cout << s.getMin() << " " << endl;
    return 0;
}
