/******************************************************************************
Validate BST 
Implement a function to check if a binary tree is a binary search tree
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Recurisve function to validate tree keys 
int isBSTaux(Node* root, int leftSon, int rightSon){
    if(root == NULL){   
        return -1;  // assuming keys are always positive
    }
    
    int min = root->val, max = root->val;
    int left = isBSTaux(root->left,1,0);
     // if error then return INT_MIN as error code 
    if(left == INT_MIN || (left != -1) && (left > root->val)){   
        return INT_MIN;
    } else if(left != -1) {
        min = left;     // declare left value as min
    }
    
    int right = isBSTaux(root->right,0,1);
     // if error then return INT_MIN as error code 
    if(right == INT_MIN || (right != -1) && (right <= root->val)){   
        return INT_MIN;
    } else if(right != -1) {
        max = right;     // declare right value as max
    }
    
    if(rightSon){   // if the node is a right son then return current min 
        return min;
    } else {        
        return max;
    }
}

// Return true if no error was passed 
bool isBST(Node* root){
    return isBSTaux(root,0,0) != INT_MIN;
}

int main()
{
    Node root(75);
    Node left(50);
    Node leftleft(0);
    Node leftright(75);
    Node right(200);
    Node rightleft(150);
    Node rightright(300);
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
