/******************************************************************************
String Rotation
Assume you have a method isSubstring which checks if one word is a is a
substring of another. Given two strings, s1 and s2, write code to check if s2
is a rotation of s1 using only one call to isSubstring
Example
"waterbottle" is a rotation of "erbottlewat"
*******************************************************************************/

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// checks if s2 is a substring of s1
bool isSubstring(string s1, string s2){
    int found = s1.find(s2);
    if (found != string::npos)
        return true;
    return false;
}

bool checkRotation(string s1, string s2){
    if(s1.length() != s2.length() || s1.empty()){
        return false;
    }
    return isSubstring(s1+s1, s2);
}

int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    if(checkRotation(s1,s2)){
        cout << s2 << " is a rotation of " << s1;
    } else {
        cout << s2 << " is NOT a rotation of " << s1;
    }
    return 0;
}