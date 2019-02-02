/******************************************************************************
Recursive Multiply
Write a recursive function to multiply two positive integers without using
the * operator (or / operator). You can use addition, subtraction, and bit shifting, but you should
minimize the number of those operations.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int multAux(int small, int big){
    if(small == 0)
        return 0;            // mult by zero is zero
    if(small == 1)          
        return big;
    
    int s = small >> 1;     // divide by 2 
    int halfSum = multAux(s,big);
    
    if(small % 2 == 0) {    // small is even
        return halfSum + halfSum;
    } else {
        return halfSum + halfSum + big;
    }
}

// Time complexity is O(log(small))
// Memory space is O(log(small))
int mult(int a, int b){
    int small = min(a,b);
    int big = max(a,b);
    return multAux(small,big);
}

int main()
{
    int x = 30;
    int y = 200;
    cout << mult(x,y);
    return 0;
}