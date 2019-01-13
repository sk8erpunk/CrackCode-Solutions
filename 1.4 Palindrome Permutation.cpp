/******************************************************************************
Palindrome Permutation
Given a string, write a function to check if it is a Permutation of a Palindrome.
Example
Input: Tact Coa 
Output: True (Permutations: "taco cat", "atco cta", etc.)
*******************************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define MAX_CHAR 256

// Time complexity is O(N) where N is the input length
// Memory space is O(1)
bool checkPalindromePermutation(string& str){
    int histogram[MAX_CHAR] = {0};
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' ')
            continue;
        if(isalpha(str[i])) // if letter
            histogram[(int)toupper(str[i])]++;  // histogram[int('A')]++
        else
            histogram[(int)str[i]]++;
    }
	// count odds
	int odd = 0;
    for(int i = 0; i < MAX_CHAR; i++){
        if(histogram[i] % 2 != 0)
            odd++;
    }
    return odd <= 1;
}

int main()
{
    string str = "Tact Cao";
    if(checkPalindromePermutation(str))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
