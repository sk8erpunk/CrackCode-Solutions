/******************************************************************************
Check Balanced 
Implement a function to check if a binary tree is balanced. For the purposes of 
this question, a balanced tree is defined to be a tree such that the heights of 
the two subtrees of any TreeNode never differ by more than one.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// Tree TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Returns the height of the tree if it's balanced else INT_MAX as error code 
int findHeight(TreeNode* root){
	if(!root) return 0;
	
	int l = findHeight(root->left) + 1;
	if(l == INT_MAX)						// If Error return ErrorCode
		return INT_MAX;
	int r = findHeight(root->right) + 1;
	if(r == INT_MAX)
		return INT_MAX;
	if(abs(l-r) > 1)						// Check balance condition
		return INT_MAX;
		
	return max(l,r);
}

// Returns if the tree is balanced or not
// Time complexity is O(N) where N is the tree size
// Memory space is O(H) where H is the tree height
bool checkBalanced(TreeNode* root){
    return findHeight(root) != INT_MAX;   
}

int main()
{
    // Tree
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(2);
    TreeNode leftleft(11);
    TreeNode leftleftleft(111);
    TreeNode leftright(12);
    TreeNode leftleftright(112);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;  
    root.left->left->left = &leftleftleft;  
    root.left->right = &leftright;
    root.left->left->right = &leftleftright; 
    TreeNode rightleft(21);
    root.right->left = &rightleft;
    
    if(checkBalanced(&root))
        cout << "True";
    else
        cout << "False";
    return 0;
}
