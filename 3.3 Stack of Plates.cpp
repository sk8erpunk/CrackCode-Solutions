/******************************************************************************
Stack of Plates 
Imagine a (literal) stack of plates. if the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack
exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
SetOfStacks should be composed of several stacks and should create a new stack 
once the previous one exceeds capacity.SetOfStacks.push() and SetOfStacks.pop()
should behave identically to a single stack.
FOLLOW UP 
Implement a function popAt(int index) which performs a pop operation on a 
specific sub-stack.
*******************************************************************************/
#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class SetOfStacks {
    
    vector<stack<int>> stacks;
    int stackNum;
    int capacity;
    
    public:
    SetOfStacks(int threshold){
        capacity = threshold;
        stackNum = -1;
    }
    void push(int item){
        if(stacks.size() == 0 || stacks[stackNum].size() >= capacity){
            stack<int> newStack;
            stacks.push_back(newStack);
            stackNum++;
        }
        stacks[stackNum].push(item);
    }
    void pop(){
        if(stacks.size() == 0){
            throw "stack is empty!"; 
        }
        stacks[stackNum].pop();
        if(stacks[stackNum].empty()){    // if current stack is empty now remove it
            stacks.pop_back();
            stackNum--;
        }
    }
    int getStackNums(){
        return stackNum + 1;
    }
    stack<int>& getStack(int index){
        if(stacks.size() == 0){
            throw "StackDoesntExistException";
        }
        return stacks[index- 1];
    }
};

void printStacks(SetOfStacks& s, int stacksNum){

    while(stacksNum){
        cout << "stack" << stacksNum << ": "; 
        stack<int>& stack = s.getStack(stacksNum);
        while(stack.size() > 0){
            cout << stack.top() << " ";
            stack.pop();
        }
        stacksNum--;
        cout << endl;
    }
}

int main()
{
    SetOfStacks set(5); 
    set.push(1);
    set.push(2);
    set.push(3);
    set.push(4);
    set.push(5);
    set.push(6);
    set.push(6);
    printStacks(set,set.getStackNums());
    return 0;
}
