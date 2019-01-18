/******************************************************************************
List Of Depths
Given a binary tree, design an algorithm which creates a linked list of all the
nodes at each depth (e.g if you have a tree with depth D, you'll have D linked
lists).
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Create linked list of nodes in every depth using BFS
// Time complexity is O(N) where N is the tree size
// Memory space is O(N) (using queue) 
map<int,list<int>> listOfDepthsBFS(TreeNode* root){
    // a map which maps depth to list of values in that depth
    map<int, list<int>> depthMap;	
	
    list<TreeNode*> queue;
    queue.push_back(root);
    
	int level = 0;
 
    // BFS iterations  
    while(!queue.empty()){
		int n = queue.size();
		list<int> currList;
		for(int i = 0; i < n; i++){
			TreeNode* node = queue.front();
			queue.pop_front();
			currList.push_back(node->val);
			if(node->left)
				queue.push_back(node->left);
			if(node->right)         
				queue.push_back(node->right);	
		}
		// Add current level
		depthMap[level++] = currList;
    }

    return depthMap;
}

// DFS AUX
void createLists(TreeNode* root, vector<vector<int>>& lists, int level){
	if(!root) return;
	
	if(lists.size() > level){
		vector<int>& levelList = lists[level];
		levelList.push_back(root->val);
	} else {
		vector<int> newLevelList;
		newLevelList.push_back(root->val);
		lists.push_back(newLevelList);
	}
	createLists(root->left, lists, level + 1);
	createLists(root->right, lists, level + 1);
}

// Create linked list of nodes in every depth using DFS
// Time complexity is O(N) where N is the tree size
// Memory space is O(LogN)  
vector<vector<int>> listOfDepthsDFS(TreeNode* root) {
	vector<vector<int>> res;
	createLists(root, res, 0);
	return res;
}

// Print result
void printResult(map<int,list<int>>& linkedLists){
    for (map<int,list<int>>::iterator it = linkedLists.begin(); it != linkedLists.end(); ++it){
        cout << "depth " << it->first << ": ";
        list<int> values = it->second;
        cout << "[";
        for (list<int>::iterator i = values.begin(); i != values.end(); ++i){
            cout << *i << " ";
        }
        cout << "]" << endl;
    } 
}


int main()
{
    // Tree
    TreeNode root(0);
    TreeNode left(10);
    TreeNode right(20);
    TreeNode leftleft(55);
    TreeNode leftright(11);
    TreeNode rightright(66);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;  
    root.left->right = &leftright;
    root.right->right = &rightright;
    
    // Result: a map of <depth, list of nodes in that depth>
    map<int,list<int>> linkedLists = listOfDepthsBFS(&root);
    
    // Print map
    printResult(linkedLists);

    return 0;
}
