/******************************************************************************
Minimal Tree 
Given a sorted (increasing order) array with unique integer elements, write an 
algorithm to create binary search tree with minimal height.
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& arr, int start, int end){
    if(start > end)
        return NULL;
    int mid = (left + right)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildTree(arr, start, mid-1);
    root->right = buildTree(arr, mid+1, end);
    return root;
}

// Time complexity is O(N) where N is the input size
// Memory space is O(logN)
TreeNode* minimalTree(vector<int>& arr){
    return buildTree(arr, 0, n-1);
}

void printInOrder(TreeNode* root){
    if(root){
        printInOrder(root->left);
        cout << root->val;
        printInOrder(root->right);
    }
}

int main()
{
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    TreeNode* root = minimalTree(arr);
    printInOrder(root);
    return 0;
}
