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


bool checkPalindromePermutation(string str){
    int odd = 0, len = 0;
    int histogram[MAX_CHAR] = {0};
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ')
            continue;
        if(isalpha(str[i]))
            histogram[(int)toupper(str[i])]++;  //histogram[int('A')]++
        else
            histogram[(int)str[i]]++;
        len++; // count chars without spaces
    }
    for(int i = 0; i < MAX_CHAR; i++){
        if(histogram[i] % 2 != 0)
            odd++;
    }
    if(len % 2 == 0)
        return (odd == 0);
    
    return (odd == 1);
}




int main()
{
    string str = "Tact Cao";
    if(checkPalindromePermutation(str)){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
