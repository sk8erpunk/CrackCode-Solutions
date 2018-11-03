/******************************************************************************
Check Subtree
T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create 
an algorithm to determine if T2 is a subtree of T1.
A tree T2 is a subtree of T1 if there exist a node n in T1 such that the subtree
of n is identical to T2. That is, if you cut off the tree at node n, the two 
trees would be identical. 
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

// tree node 
struct Node {
    int val;
    Node* right;
    Node* left;
    Node(int x) : val(x), right(NULL), left(NULL) {}
};

// checks if t1 is identical to t2 
bool ifIdentical(Node* t1, Node* t2){
    if(t1 == NULL && t2 == NULL){
        return true;
    }
    if(t1 == NULL || t2 == NULL){
        return false;
    }
    if(t1->val != t2->val){
        return false;
    }
    return ifIdentical(t1->left,t2->left) && ifIdentical(t1->right,t2->right);
}

// recursive function to check if t1 has subtree identical to t2
bool serachSubTree(Node* t1, Node* t2){
    if(t1 == NULL){
        return false;
    }
    if(t1->val == t2->val && ifIdentical(t1,t2)){
        return true;
    }
    return serachSubTree(t1->left,t2) || serachSubTree(t1->right, t2);
}

// checks if t2 is a subtree of t1
bool checkSubtree(Node* t1, Node* t2){
    if(t2 == NULL) {
        return true;
    }
    return serachSubTree(t1,t2);
}

int main()
{
    // Tree 1
    Node root(3);
    Node left(2);
    Node leftleft(1);
    Node leftright(4);
    Node leftrightright(6);
    Node leftrightleft(5);
    Node right(7);
    Node rightright(8);
    
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;
    root.left->right = &leftright;
    root.left->right->left = &leftrightleft;
    root.left->right->right = &leftrightright;
    root.right->right = &rightright;
    
    // Tree 2
    Node root2(4);
    Node left2(5);
    Node right2(7);
    root2.left = &left2;
    root2.right = &right2;
    
    if(checkSubtree(&root, &root2)){
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
