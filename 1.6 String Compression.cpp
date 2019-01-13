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
#include <sstream>

using namespace std;

// Time complexity is O(N) where N is the input length
// Space complexity is O(N)
string stringCompression(string& str){
    stringstream compressed;
    int i = 0;
    while(i < str.size()) {
        char c = str[i];
        int count = 0;
        while(i < str.size() && str[i] == c){
            count++;
            i++;
        }
        compressed << c << to_string(count); 
    }
	string cs = compressed.str();
    return cs.size() > str.size() ? str : cs;
}

int main()
{
    string str = "aabcccccaaa";
    cout << stringCompression(str);
    return 0;
}
