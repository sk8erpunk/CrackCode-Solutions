/******************************************************************************
Triple Step
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs.
*******************************************************************************/

#include <iostream>

using namespace std;

int tripleStepsAux(int n, int* memo){
	if(n < 0)
		return 0;
	else if(n == 0)
	    return 1;
	else if(memo[n] > 0)
		return memo[n];
	else
	    memo[n] = tripleStepsAux(n-1, memo) + tripleStepsAux(n-2, memo) + tripleStepsAux(n-3, memo);
	return memo[n];
}

// Time complexity is O(n)
// Memory space is O(n)
int tripleSteps(int n){
	int* memo = new int[n+1];
	for(int i = 0; i < n+1; i++)
		memo[i] = 0;
	int steps = tripleStepsAux(n, memo);
	delete[] memo;
	return steps;
}

int main()
{
	int n = 10;
    cout << "Number of ways: " << tripleSteps(n);
    return 0;
}
