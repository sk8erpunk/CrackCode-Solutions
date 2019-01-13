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

// check if str1 and str2 has a replacement of one letter
bool checkReplacement(string& str1, string& str2){
    int i = 0, j = 0;
    bool diff = false;
    while(i < str1.size() && j < str2.size()){
        if(str1[i++] != str2[j++]){
            if(diff) // already found a replacemnet
                return false;
            diff = true;
        }
    }
    return true;
}

// str1 is the longer string 
bool checkOneLetterDifference(string& str1, string& str2){
    int i = 0, j = 0;
	bool diff = false;
    while(i < str1.length() && j < str2.length()){
        if(str1[i] != str2[j]){
            if(diff)	// already found two different letters 
                return false;
            diff = true;
            i++; 		// move str1 ptr
        } else {
            i++;
            j++;
        }
    }
    return true;
}

// Time complexity is O(N) where N is the shorter input
// Memory space is O(1)
bool editOneAway(string& str1, string& str2){
    if(str1.length() == str2.length()){
        return checkReplacement(str1, str2);			// replacemnet
    } else if (str1.length() == str2.length() + 1){
        return checkOneLetterDifference(str1, str2);	// insertion
    } else if (str1.length() == str2.length() - 1){ 
        return checkOneLetterDifference(str2, str1);	// removal
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