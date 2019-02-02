/******************************************************************************
Magic Index 
A magic index in an array A[ 1 .•. n-1] is defined to be an index such that A[ i]
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
array A.
FOLLOW UP
What if the values are not distinct?
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Find index without distint numbers in array
int magicIndexWithDistinct(vector<int>& arr, int start, int end){
	if(start > end)
		return -1;
	
	int mid = (start+end)/2;
	if(arr[mid] == mid)
		return mid;
	else if(arr[mid] < mid)
		return magicIndexWithDistinct(arr, mid+1, end);
	else
		return magicIndexWithDistinct(arr, start, mid-1);
}

// Magic index with distinct Numbers
// Time complexity is O(logN) where N is the input size
// Memory space is O(LogN) 
int magicIndex1(vector<int> arr){
	return magicIndexWithDistinct(arr, 0, arr.size()-1);
}

int magicIndexWithoutDistinct(vector<int>& arr, int start, int end){
	if(start > end)
		return -1;
	
	int mid = (start+end)/2;
	if(arr[mid] == mid)
		return mid;
		
	int leftIndex = min(mid-1, arr[mid]);
	int left = magicIndexWithoutDistinct(arr, start, leftIndex);
	if(left > -1)
	    return left;
	
	int rightIndex = max(mid+1, arr[mid]);
	int right = magicIndexWithoutDistinct(arr, rightIndex, end);
	return right;
}

// FOLLOW UP
// Magic index without distinct Numbers
// Time complexity is O(N) where N is the input size
// Memory space is O(LogN) 
int magicIndex2(vector<int> arr){
	return magicIndexWithoutDistinct(arr, 0, arr.size()-1);
}


int main() {
	vector<int> arr = {-10,-3,1,4,5,5,7};
	cout << magicIndex2(arr) << endl;
	return 0;
}