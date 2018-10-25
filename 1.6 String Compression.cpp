/******************************************************************************
String Compression:
Implement a method to perform basic string compression using the counts of
repeated characters. For example the string aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than the original string, 
your method should return the original string. You can assume the string has 
only uppercase and lowercase letters (a-z).
*******************************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string stringCompression(string s){
    string compressed = "";
    int i = 0;
    while(i < s.length()) {
        char c = s[i];
        int clen = 0;
        while(i < s.length() && s[i] == c){
            clen++;
            i++;
        }
        compressed += c + to_string(clen); 
    }
    if(compressed.length() > s.length()){
        return s;
    }
    return compressed;
}

int main()
{
    string str = "aabcccccaaa";
    cout << stringCompression(str);
    
    return 0;
}
