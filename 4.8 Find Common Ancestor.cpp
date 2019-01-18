/******************************************************************************
First Common Ancestor 
Design an algorithm and write code to find the first common ancestor of two TreeNodes
in a binary tree. Avoid storing additional TreeNodes in a data structure. Note: This 
is not necessarily a binary search tree.
*******************************************************************************/
#include <stdio.h>
#include <cmath>
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

// return root depth
int findDepth(TreeNode* root){
    int d = 0;
    while(root->parent){
        d++;
        root = root->parent;
    }
    return d;
}


// Time complexity is O(D) where D is the depth of the deeper node 
// Memory space is O(D)
TreeNode* findFirstCommonAncestor(TreeNode* node1, TreeNode* node2){
    if(!node1 || !node2) return NULL;
 
    // find node's depths 
    int d1 = findDepth(node1);  
    int d2 = findDepth(node2);
    
    int distance = abs(d1-d2);
    TreeNode* deeper = d1 > d2 ? node1 : node2;
    TreeNode* closer = d1 > d2 ? node2 : node1;
    
    // move deeper node to the same level as closer node 
    while(distance){
        deeper = deeper->parent;
        distance--;
    }
    
    // find intersection point 
    while(deeper != closer){
        deeper = deeper->parent;
        closer = closer->parent;
    }
    return deeper;
}

int main()
{
    TreeNode root(1);
    TreeNode left(2);
    TreeNode leftleft(0);
    TreeNode leftright(70);
    TreeNode leftrightright(90);
    TreeNode leftrightleft(44);
    TreeNode leftrightleftright(50);
    TreeNode right(200);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;
    root.left->right = &leftright;
    root.left->right->left = &leftrightleft;
    root.left->right->left->right = &leftrightleftright;
    root.left->right->right = &leftrightright;

    left.parent = &root;
    right.parent = &root;
    leftleft.parent = &left;
    leftright.parent = &left;
    leftrightright.parent = &leftright;
    leftrightleft.parent = &leftright;
    leftrightleftright.parent = &leftrightleft;
    
    cout << findFirstCommonAncestor(&left,&leftrightleftright)->val;
    
    return 0;
}
