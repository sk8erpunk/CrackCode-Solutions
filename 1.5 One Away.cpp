/******************************************************************************
One Away 
There are three types of edits that can be performed on strings: insert a
character, remove a character or replace a character. Give two strings, write a 
function to check if they are one edit(or zero edits) away.
*******************************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
bool checkReplacement(string str1, string str2){
    int i = 0, j = 0;
    int len1 = str1.length(), len2 = str2.length();
    int diff = 0;
    while(i < len1 && j < len2){
        if(str1[i] != str2[j]){
            if(diff){
                return false;
            }
            diff++;
        }
        i++;
        j++;
    }
    return true;
}

// str1 is the longer string 
bool checkOneLetterDifference(string str1, string str2){
    int i = 0, j = 0, diff = 0;
    while(i < str1.length() && j < str2.length()){
        if(str1[i] != str2[j]){
            if(diff) {          // if already two different letters 
                return false;
            }
            diff++;
            i++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}
bool editOneAway(string str1, string str2){
    
    if(str1.length() == str2.length()){
        return checkReplacement(str1, str2);
    } else if (str1.length() == str2.length() + 1){
        return checkOneLetterDifference(str1, str2);
    } else if (str1.length() == str2.length() - 1){ 
        return checkOneLetterDifference(str2, str1);
    }
    return false;
}
int main()
{
    string str1 = "pale";
    string str2 = "ple";
    if(editOneAway(str1, str2)){
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
