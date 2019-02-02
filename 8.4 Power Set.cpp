/******************************************************************************
Power Set
Write a method to return all subsets of a set.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Time complexity is O(N*2^N) 
// Memory space is O(N*2^N)
vector<vector<int>> findSubsets(vector<int>& arr){
	vector<vector<int>> subsets;
	vector<int> emptySet;
	subsets.push_back(emptySet);
	for(int i = 0; i < arr.size(); i++){
	    int n = subsets.size();
		for(int j = 0; j < n; j++){
 			vector<int> unionSet = subsets[j];
 			unionSet.push_back(arr[i]);
 			subsets.push_back(unionSet);
		}
	}
	return subsets;
}


int main()
{
    vector<int> arr = {1,2,3,4,5,6};
	vector<vector<int>> ans = findSubsets(arr);
	for(int i = 0; i < ans.size(); i++){
		cout << "subset" << i << ": { "; 
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << "}" << endl;
	}
    return 0;
}
