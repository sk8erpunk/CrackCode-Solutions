/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
#define MAX_CHAR 256


bool isUnique(string str){
    int chars[MAX_CHAR] = { 0 };
    for(int i = 0; i < str.length(); i++){
        if(++chars[str[i]] > 1){
            return false;
        }
    }
    
    return true;
}


int main()
{
    string str = "hello world";
    if(isUnique(str)){
        cout << "String is unique!";
    } else {
        cout << "String is not unique!";
    }
    
    return 0;
}
