/******************************************************************************
Successor 
Write an algorithm to find the "next" node of a given node in a binary search 
tree. You may assume that each node has a link to its parent. 
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

Node* findSuccessor(Node* node){
    if(!node){
        return NULL;
    }
    Node* n = node;
    if(n->right){
        n = n->right;
        while(n->left){
            n = n->left;
        }
        return n;
    } else {
        while(n->parent && n->parent->right == n){
            n = n->parent;   
        }
        return n->parent;
    }
}


int main()
{
    Node root(100);
    Node left(50);
    Node leftleft(0);
    Node leftright(70);
    Node right(200);
    Node rightleft(150);
    Node rightright(300);
    Node rightleftright(170);
    Node leftrightright(90);
    Node rightleftleft(120);
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
    
    Node* next = findSuccessor(&root);
    if(next == NULL){
        cout << "The given node is the last element, so there is no next element";   
    } else {
        cout << next->val; 
    }
    return 0;
}
