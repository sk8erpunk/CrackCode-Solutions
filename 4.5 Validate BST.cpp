/******************************************************************************
Validate BST 
Implement a function to check if a binary tree is a binary search tree
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

// Tree TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recurisve function to validate BST
bool isBSTaux(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
	if(!root) 
		return true;
	if(minNode && root->val <= minNode->val)
		return false;
	if(maxNode && root->val >= maxNode->val)
		return false;
	
	return isBSTaux(root->left, minNode, root) && isBSTaux(root->right, root, maxNode);
    
}

// Time complexity is O(N) where N is the tree size
// Memory space is O(D) where D is the depth of the tree 
bool isBST(TreeNode* root){
    return isBSTaux(root, NULL, NULL);
}

int main()
{
    TreeNode root(75);
    TreeNode left(50);
    TreeNode leftleft(0);
    TreeNode leftright(75);
    TreeNode right(200);
    TreeNode rightleft(150);
    TreeNode rightright(300);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;
    root.right->left = &rightleft;
    root.left->right = &leftright;
    root.right->right = &rightright;
    
    if(isBST(&root)){
        cout << "True";
    } else {
        cout << "False";  
    }
    return 0;
}
