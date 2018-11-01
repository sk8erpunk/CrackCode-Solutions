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

using namespace std;

// Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Create linked list of nodes in every depth
map<int,list<int>> listOfDepths(Node* root){
    // BFS queue: holds pairs of (node,depth)
    list<pair<Node*,int>> queue;
    
    // a map which maps depth to list of values in that depth
    map<int, list<int>> depthMap;

    // add root to queue
    pair<Node*,int> p(root,0);
    queue.push_back(p);
    
    // add root->val to depth list in map
    depthMap[0].push_back(root->val);
 
    // BFS iterations  
    while(queue.empty() == false){
        Node* node = queue.front().first;
        int node_depth = queue.front().second;

        if(node->left){
            // add left node to map and to queue
            depthMap[node_depth + 1].push_back(node->left->val);
            pair<Node*,int> left(node->left, node_depth+1);
            queue.push_back(left);
        }
        if(node->right){            
            // add right node to map and to queue
            depthMap[node_depth + 1].push_back(node->right->val);
            pair<Node*,int> right(node->right, node_depth+1);
            queue.push_back(right);
        }
        queue.pop_front();
    }

    return depthMap;
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
    Node root(0);
    Node left(10);
    Node right(20);
    Node leftleft(55);
    Node leftright(11);
    Node rightright(66);
    root.left = &left;
    root.right = &right;
    root.left->left = &leftleft;  
    root.left->right = &leftright;
    root.right->right = &rightright;
    
    // Result: a map of <depth, list of nodes in that depth>
    map<int,list<int>> linkedLists = listOfDepths(&root);
    
    // Print map
    printResult(linkedLists);

    return 0;
}
