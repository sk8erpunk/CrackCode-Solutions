/******************************************************************************
First Common Ancestor 
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. Note: This 
is not necessarily a binary search tree.
*******************************************************************************/
#include <stdio.h>
#include <cmath>
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

// get node depth
int getHeight(Node* node){
    int h = 0;
    Node* n = node;
    while(n->parent){
        h++;
        n = n->parent;
    }
    return h;
}

Node* findFirstCommonAncestor(Node* node1, Node* node2){
    if(!node1 || !node2){
        return NULL;
    }
    // find the nodes depths 
    int h1,h2;
    h1 = getHeight(node1);  
    h2 = getHeight(node2);
    
    int distance = abs(h1-h2);
    Node* deeper = h1 > h2 ? node1 : node2;
    Node* closer = h1 > h2 ? node2 : node1;
    
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
    Node root(1);
    Node left(2);
    Node leftleft(0);
    Node leftright(70);
    Node leftrightright(90);
    Node leftrightleft(44);
    Node leftrightleftright(50);
    Node right(200);
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
