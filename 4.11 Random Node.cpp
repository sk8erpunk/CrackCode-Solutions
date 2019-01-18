/******************************************************************************
Random Node
You are implementing a binary search tree class from scratch, which, in addition
to insert, find, and delete, has a method getRandomNode() which returns a random node
from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
for getRandomNode, and explain how you would implement the rest of the methods.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;

// Define TreeNode 
struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
	int size;			// subtree size
    TreeNode(int x) : val(x), right(NULL), left(NULL), size(1){}
};

// Define Binary Search Tree
class Tree {
	
	private:
	TreeNode* root;
	
	// search value 
	bool search(TreeNode* root, int value){
	    if(!root) return false;
		else if(value == root->val)
			return true;
		else if(value < root->val)
			return search(root->left, value);
		else
			return search(root->right,value);
	}
	
	// insert value
	void insertInOrder(TreeNode* root, int value){
		root->size++;
		if(value < root->val){
			if(!root->left)
				root->left = new TreeNode(value);
			else 
				insertInOrder(root->left, value);
		} else {
			if(!root->right)
				root->right = new TreeNode(value);
			else 
				insertInOrder(root->right, value);
		}
	}
	
	// return ith node 
	TreeNode* getIthNode(TreeNode* root, int i){
		int leftSize = root->left ? root->left->size : 0;
		if(i < leftSize) 	// i between 0 - leftSize (exclusive)
			return getIthNode(root->left, i);
		else if (i == leftSize)
			return root;
		else				// i between leftSize() + 1 to size 
			return getIthNode(root->right, i - (leftSize + 1));		
	}
	
	public:
	// c'tor 
	Tree(): root(NULL){
	    
	}
	
	// insert value - O(D) where D is the tree's depth  
	void insert(int value){
		if(!root)
			root = new TreeNode(value);
		else 
		    insertInOrder(root, value);
	}
	
	// find value - O(D) where D is the tree's depth  
	bool find(int value){
		if(!root) return NULL;
		return search(root,value);
	}
	
	// get random - O(D) where D is the tree's depth 
	TreeNode* getRandomNode(){
		if(!root) return NULL;
		srand (time(NULL));
		int i = rand() % root->size;	// 0 to size(exclusive)
		cout << i << endl;
		return getIthNode(root, i);
	}
	
	// get size - O(1)
	int size(){
		return root ? root->size : 0; 
	}
};


int main() {
    
    Tree tree;
    tree.insert(70);
    tree.insert(90);
    tree.insert(50);
    tree.insert(44);
    tree.insert(10);
    cout << tree.getRandomNode()->val << endl;
    return 0;
}
