/******************************************************************************
Three in One
Describe how you could use a single array to implement three stacks
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

#define STACKS_NUM 3

class FixedThreeStacks {
    
	int stackCapacity;              // stack capacity
	int sizes[STACKS_NUM] = {0};    // stacks sizes 
	int* values;                    // three stacks values 
	
	public:
	FixedThreeStacks(int capacity){
		this->stackCapacity = capacity;
		this->values = new int[capacity * STACKS_NUM];
		for(int i = 0; i < capacity * STACKS_NUM; i++)
			values[i] = 0;
	}
	
	void push(int stackNum, int val){
		if(isFull(stackNum))
			throw "Error: stack is full!";
		values[getTopIdx(stackNum) + 1] = val;
		sizes[stackNum]++;
	}
	
	int pop(int stackNum){
		if(isEmpty(stackNum))
			throw "Error: stack is empty!";
		int idx = getTopIdx(stackNum);
		int val = values[idx];
		values[idx] = 0;
		sizes[stackNum]--;
		return val;
	}
	
	int peek(int stackNum){
		if(isEmpty(stackNum))
			throw "Error: stack is empty!";
		return values[getTopIdx(stackNum)];
	}
	
	bool isFull(int stackNum){
		return sizes[stackNum] == stackCapacity;
	}
	
	bool isEmpty(int stackNum){
		return sizes[stackNum] == 0;
	}
	
	int getTopIdx(int stackNum){
	    int ofst = stackNum * stackCapacity;
		int idx = ofst + sizes[stackNum] - 1;
		return idx;
	}
};

int main() {
    FixedThreeStacks stacks(3);
    stacks.push(0,1);
    stacks.push(0,6);
    stacks.push(0,11);
    stacks.push(1,1);
    stacks.push(1,7);
    stacks.push(1,12);
    stacks.push(2,1);
    stacks.push(2,8);
    stacks.push(2,10);
    cout << stacks.pop(0) << endl;
    cout << stacks.pop(0) << endl;
    cout << stacks.pop(1) << endl;
    cout << stacks.pop(1) << endl;
    cout << stacks.pop(2) << endl;
    cout << stacks.pop(2) << endl;
    cout << stacks.peek(0) << endl;
    cout << stacks.peek(1) << endl;
    cout << stacks.peek(2) << endl;
    return 0;
}