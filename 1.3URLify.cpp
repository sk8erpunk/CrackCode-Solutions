/******************************************************************************
URLify
write a method to replace all spaces in a string with %20. Assume the string has
a sufficient space at the end to hold the additional characters and that you are 
given the true length of the string.
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void urlify(string& str, int strLen){
    int space_count = 0;
    for(int i = 0; i < strLen; i++){
        if(str[i] == ' ') {
            space_count++;
        }
    }
    int pEnd = strLen + 2*space_count;
    pEnd--;
    for(int i = strLen - 1; i >= 0; i--){
        if(str[i] == ' '){
            str[pEnd--] = '0';
            str[pEnd--] = '2';
            str[pEnd--] = '%';
        } else {
            str[pEnd--] = str[i];
        }
    }
    cout << str;
}

int main()
{
    // assuming x is the extra space
    string str ="Mr John Smithxxxx";
    urlify(str,13);
    return 0;
}
