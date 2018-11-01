/******************************************************************************
Minimal Tree 
Given a sorted (increasing order) array with unique integer elements, write an 
algorithm to create binary search tree with minimal height.
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
 
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


Node* minimalTreeAux(int* arr, int left, int right){
    if(left > right){
        return NULL;
    }
    int mid = (left + right)/2;
    Node* root = new Node(arr[mid]);
    root->left = minimalTreeAux(arr, left, mid-1);
    root->right = minimalTreeAux(arr, mid+1, right);
    return root;
}

Node* minimalTree(int* arr, int n){
    if(!arr){
        return NULL;
    }
    return minimalTreeAux(arr, 0, n-1);
}

void printInOrder(Node* root){
    if(root != NULL){
        printInOrder(root->left);
        cout << root->val;
        printInOrder(root->right);
    }
}

int main()
{
    int N = 9;
    int arr[N] = {0,1,2,3,4,5,6,7,8};
    Node* root = minimalTree(arr, N);
    printInOrder(root);
    return 0;
}
