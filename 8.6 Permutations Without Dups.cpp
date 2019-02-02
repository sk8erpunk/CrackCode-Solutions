/******************************************************************************
Permutations without Dups
Write a method to compute all permutations of a string of unique
characters.
*******************************************************************************/

#include <iostream>
#include <string>
#include <list>

using namespace std;


// Time complexity is O(N^2*N!)
// Memory space is O(N!)
list<string> findPermutation(string& str){
	list<string> permutations;
	if(str.empty()){
		permutations.push_back("");
		return permutations;
	}
	
	permutations.push_back(str.substr(0,1));	// add first letter
	for(int i = 1; i < str.size(); i++){
		int n = permutations.size();
		for(int j = 0; j < n; j++){
			string curr = permutations.front();
			permutations.pop_front();
			for(int k = 0; k <= curr.size(); k++){
				string s = curr;
				string c(1,str[i]);
				s.insert(k,c);				// add next letter in pos k
				permutations.push_back(s);	
			}
		}
	}
	return permutations;
}



int main()
{
    string str = "abc";
	list<string> permutations = findPermutation(str);
	for(auto &p : permutations)
		cout << p << endl;
    return 0;
}