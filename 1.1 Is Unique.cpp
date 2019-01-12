/******************************************************************************
Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_CHAR 256

// Time complexity is O(N) where N is the length of input
// Memory space is O(1)
bool isUnique(string& str){
    vector<int> chars(MAX_CHAR,0);	// init to zeroes
    for(int i = 0; i < str.length(); i++){
        if(++chars[(int)str[i]] > 1){
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "hello world";
    if(isUnique(str))
        cout << "String is unique!";
    else 
        cout << "String is not unique!";
    
    return 0;
}
