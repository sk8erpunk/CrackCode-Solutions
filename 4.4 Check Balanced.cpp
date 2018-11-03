/******************************************************************************
Check Balanced 
Implement a function to check if a binary tree is balanced. For the purposes of 
this question, a balanced tree is defined to be a tree such that the heights of 
the two subtrees of any node never differ by more than one.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


// Returns the height of the tree if it's balanced 
int checkBalancedAux(Node* root){
    if(root == NULL){   // If it is a leaf 
        return -1;
    }
    
    int left_height = checkBalancedAux(root->left) + 1;
    if(left_height == INT_MAX){ // If left subtree isn't balanced 
        return INT_MAX;         // Return error value
    }
    int right_height = checkBalancedAux(root->right) + 1;
    if(right_height == INT_MAX){    // If left subtree isn't balanced 
        return INT_MAX;             // Return error value
    }
    if(abs(left_height - right_height) > 1){    
        return INT_MAX;         // Return error value
    }
    return max(left_height,right_height);
}

// Returns if the tree is balanced or not
bool checkBalanced(Node* root){
    return checkBalancedAux(root) != INT_MAX;   
}


int main()
{
        // Tree
    Node root(0);
    Node left(1);
    Node right(2);
    Node leftleft(11);
    Node leftleftleft(111);
    Node leftright(12);
    Node leftleftright(112);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;  
    root.left->left->left = &leftleftleft;  
    root.left->right = &leftright;
    root.left->left->right = &leftleftright; 
    //Node rightleft(21);
    //root.right->left = &rightleft;
    
    if(checkBalanced(&root)){
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
