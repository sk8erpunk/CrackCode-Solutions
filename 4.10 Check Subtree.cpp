/******************************************************************************
Check Subtree
T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create 
an algorithm to determine if T2 is a subtree of T1.
A tree T2 is a subtree of T1 if there exist a TreeNode n in T1 such that the subtree
of n is identical to T2. That is, if you cut off the tree at TreeNode n, the two 
trees would be identical. 
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

// TreeNode 
struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

// Checks if t1 is identical to t2 
bool ifIdentical(TreeNode* t1, TreeNode* t2){
    if(!t1 && !t2)
        return true;
    if(!t1 || !t2)
        return false;
    return (t1->val == t2->val) && ifIdentical(t1->left,t2->left) && ifIdentical(t1->right,t2->right);
}

// Checks if t2 is a subtree of t1 without additional data structure
// Time complexity is O(N+M)
// Memory space is O(logN + logM)
bool checkSubtree(TreeNode* t1, TreeNode* t2){
    if(!t2) return t2 == NULL;
    return ifIdentical(t1,t2) || checkSubtree(t1->left,t2) || checkSubtree(t1->right,t2);
}

int main()
{
    // Tree 1
    TreeNode root(3);
    TreeNode left(2);
    TreeNode leftleft(1);
    TreeNode leftright(4);
    TreeNode leftrightright(6);
    TreeNode leftrightleft(5);
    TreeNode right(7);
    TreeNode rightright(8);
    
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;
    root.left->right = &leftright;
    root.left->right->left = &leftrightleft;
    root.left->right->right = &leftrightright;
    root.right->right = &rightright;
    
    // Tree 2
    TreeNode root2(4);
    TreeNode left2(5);
    TreeNode right2(7);
    root2.left = &left2;
    root2.right = &right2;
    
    if(checkSubtree(&root, &root2)){
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
