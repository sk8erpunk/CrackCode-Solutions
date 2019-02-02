/******************************************************************************
Permutations with Duplicates
Write a method to compute all permutations of a string whose
characters are not necessarily unique. The list of permutations should not have duplicates.
*******************************************************************************/

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

// Count chars appearance in str 
void fillMap(unordered_map<char,int>& map, string& str){
	for(int i = 0; i < str.size(); i++){
		if(map.count((char)str[i]) == 0)
			map[(char)str[i]] = 0;
		map[(char)str[i]]++;
	}
}

// Recursive function to find permutations
void findPermutation(unordered_map<char,int>& map, string prefix, int remaining, list<string>& permutations){
	if(remaining == 0){						// no remaining letters so push current permuatation
		permutations.push_back(prefix);		
		return;
	}
	for(auto &p: map){
		string c(1,p.first);	
		if(p.second > 0){ 	
			p.second--;
			findPermutation(map, prefix + c, remaining - 1, permutations);
			p.second++;
		}
	}
}

// Time complexity is O(N!)
// Memory space is O(N) Where N is the input size 
list<string> findPermutation(string& str){
	list<string> permutations;
	unordered_map<char,int> map;
	fillMap(map,str);
	findPermutation(map, "", str.length(), permutations);
	return permutations;
	
}

int main()
{
    string str = "aabbcc";
	list<string> permutations = findPermutation(str);
	for(auto &p : permutations)
		cout << p << endl;
    return 0;
}