/******************************************************************************
Sort Stack
Write a program to sort a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements 
into any other data structure (such as an array). The stack supports the
following operations: push, pop, peek, and isEmpty().
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& s){
    if(s.empty()){
        throw "Empty stack!";
    }
    stack<int> temp;
    while(s.empty() == false){
        int x = s.top();
        s.pop();
        while(temp.empty() == false && temp.top() > x){
            s.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }
    // fill s back with sorted elements in temp 
    while(temp.empty() == false){
        s.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<int> s){
    cout << "top<-"; 
    while(s.empty() == false){
        cout << s.top() << "<-";
        s.pop();
    }
    cout << "base" << endl;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(8);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(6);
    printStack(s);
    sortStack(s);
    printStack(s);
    return 0;
}
