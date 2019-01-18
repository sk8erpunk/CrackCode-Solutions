/******************************************************************************
Paths with Sum
You are given a binary tree in which each node contains an integer value (which
might be positive or negative). Design an algorithm to count the number of paths that sum to a
given value. The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unordered_map> 

using namespace std;

// Define TreeNode 
struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

void setPathCount(unordered_map<int,int>& countPathsMap, int runningSum, int val){
	int pc = countPathsMap.count(runningSum) ? countPathsMap[runningSum] : 0; // current count of this sum
	pc += val;	// update it (+1 / -1)
	if(pc == 0)	
		countPathsMap.erase(runningSum); // if it doesnt exist anymore, remove it
	else
		countPathsMap[runningSum] = pc; // else update it
}

int countPaths(TreeNode* root, int targetSum, int runningSum, unordered_map<int,int>& countPathsMap){
	if(!root) 
		return 0;
	
	// add to running sum
	runningSum += root->val; 
	
	// current total paths that has target sum
	int totalPaths = countPathsMap.count(runningSum - targetSum) ? countPathsMap[runningSum - targetSum] : 0; 
	
	// add another path
	if(runningSum == targetSum)
		totalPaths++;
	setPathCount(countPathsMap, runningSum ,1);
	totalPaths += countPaths(root->left, targetSum, runningSum, countPathsMap);
	totalPaths += countPaths(root->right, targetSum, runningSum, countPathsMap);
	setPathCount(countPathsMap, runningSum, -1);
	return totalPaths;
}

// Time complexity is O(N) where N is the number of nodes in the tree
// Memory space is O(logN) in a balance  
int countPathsWithSum(TreeNode* root, int targetSum){
	unordered_map<int,int> countPathsMap;
	return countPaths(root, targetSum, 0, countPathsMap);
}

int main() {
    // Tree 
    TreeNode root(10);
    TreeNode left(5);
    TreeNode leftleft(3);
    TreeNode leftleftleft(3);
    TreeNode leftleftright(-2);
    TreeNode leftright(1);
    TreeNode leftrightright(2);
    TreeNode right(-3);
    TreeNode rightright(11);
    
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;
    root.left->left->left = &leftleftleft;
    root.left->left->right = &leftleftright;
    root.left->right = &leftright;
    root.left->right->right = &leftrightright;
    root.right->right = &rightright;
    
    cout << countPathsWithSum(&root, 6) << endl;
	return 0;
}