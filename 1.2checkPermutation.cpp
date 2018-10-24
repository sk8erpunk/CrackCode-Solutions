/******************************************************************************
Check Permutation 
Given two strings, write a method to decide if one is a permutation of the 
other.
*******************************************************************************/
#include <iostream>
#include <string>
#define MAX_CHAR 256

using namespace std;

bool checkPermutation(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int chars[MAX_CHAR] = {0};
    int i;
    for(i = 0; i < str1.length(); i++){
        chars[str1[i]]++;
        chars[str2[i]]--;
    }
    for(i = 0; i < MAX_CHAR; i++){
        if(chars[i]){
            return false;
        }
    }
    return true;
}


int main()
{
    string str1 = "Hello world";
    string str2 = "w llloeoHrd";
    if(checkPermutation(str1,str2)){
        cout << "str2 is a permutation of str1";
    } else {
        cout << "str2 is not a permutation of str1";
    }
    return 0;
}
