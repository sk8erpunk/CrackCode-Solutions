/******************************************************************************
Successor 
Write an algorithm to find the "next" TreeNode of a given TreeNode in a binary search 
tree. You may assume that each TreeNode has a link to its parent. 
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

// TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

// Time complexity is O(H) where H is the tree height
// Memory space is O(1)
TreeNode* findSuccessor(TreeNode* n){
    if(!n) return NULL;
    if(n->right){
        n = n->right;
        while(n->left)
            n = n->left;
        return n;
    } else {
        while(n->parent && n->parent->right == n)
            n = n->parent;   
        return n->parent;
    }
}


int main()
{
    TreeNode root(100);
    TreeNode left(50);
    TreeNode leftleft(0);
    TreeNode leftright(70);
    TreeNode right(200);
    TreeNode rightleft(150);
    TreeNode rightright(300);
    TreeNode rightleftright(170);
    TreeNode leftrightright(90);
    TreeNode rightleftleft(120);
    root.left = &left;
    left.parent = &root;
    root.right = &right;
    right.parent = &root;
    root.left->left = &leftleft;
    leftleft.parent = &left;
    root.right->left = &rightleft;
    rightleft.parent = &right;
    root.left->right = &leftright;
    leftright.parent = &left;
    root.right->right = &rightright;
    rightright.parent = &right;
    rightleftright.parent = &rightleft;
    rightleft.right = &rightleftright;
    leftrightright.parent = &leftright;
    leftright.right = &leftrightright;
    rightleftleft.parent = &rightleft;
    rightleft.left = &rightleftleft;
    
    TreeNode* next = findSuccessor(&root);
    if(next == NULL){
        cout << "The given TreeNode is the last element, so there is no next element";   
    } else {
        cout << next->val; 
    }
    return 0;
}
