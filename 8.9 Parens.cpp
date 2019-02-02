/******************************************************************************
Parens
Implement an algorithm to print all valid (i.e., properly opened and closed) combinations
of n pairs of parentheses.
EXAMPLE
Input: 3
Output: (( () ) ) , ( () () ) , ( () ) () , () ( () ) , () () ()
*******************************************************************************/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

// My Solution
list<string> findParens(int n){
    unordered_set<string> hashSet;
	list<string> parensList;
	parensList.push_back("");
	for(int i = 0; i < n; i++){
		int m = parensList.size();
		for(int j = 0; j < m; j++){
			string curr = parensList.front();
			parensList.pop_front();
			hashSet.erase(curr);
			for(int k = 0; k <= curr.size(); k++){
				string p = curr;
				p.insert(k,"()");				// add parens in pos k
				if(hashSet.count(p) == 0){
					hashSet.insert(p);
				    parensList.push_back(p);
				}
			}
		}
	}
	return parensList;
}


void findParensRecursive(list<string>& allParens, int leftParens, int rightParens, vector<char>& p, int index){
    if(leftParens < 0 || rightParens < leftParens)
        return;
        
    if(leftParens == 0 && rightParens == 0){
        string s(p.begin(),p.end());
        allParens.push_back(s);
    } else {
        p[index] = '(';
        findParensRecursive(allParens, leftParens-1, rightParens, p, index+1);
        
        p[index] = ')';
        findParensRecursive(allParens, leftParens, rightParens-1, p, index+1);
    }
}

// Better Solution
list<string> findParens2(int n){
    list<string> allParens;
    vector<char> p(n*2,'0');
    findParensRecursive(allParens,n,n,p,0);
    return allParens;
}


int main()
{
    int n = 3;
	list<string> parens1 = findParens(n);
	list<string> parens2 = findParens2(n);
	for(auto &p : parens2)
		cout << p << " ";
    return 0;
}