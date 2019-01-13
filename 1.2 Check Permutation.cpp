/******************************************************************************
Check Permutation 
Given two strings, write a method to decide if one is a permutation of the 
other.
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

#define MAX_CHAR 256

using namespace std;

// Time complexity is O(N) where N is the input length
// Memory space is O(1)
bool checkPermutation(string& str1, string& str2){
    if(str1.length() != str2.length())
        return false;
	
	// str1.size() == str2.size()
    vector<int> chars(MAX_CHAR,0);
    for(int i = 0; i < str1.size(); i++){
        chars[(int)str1[i]]++;
    }
    for(int i = 0; i < str2.size(); i++){
		chars[(int)str2[i]]--;
        if(chars[i] < 0)
            return false;
    }
    return true;
}


int main()
{
    string str1 = "Hello world";
    string str2 = "w llloeoHrd";
    if(checkPermutation(str1,str2))
        cout << "str2 is a permutation of str1";
    else 
        cout << "str2 is not a permutation of str1";
    return 0;
}
