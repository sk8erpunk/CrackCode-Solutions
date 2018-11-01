/******************************************************************************
Route Between Nodes
Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes.
*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/* 
* Graph Class
* v: the number of nodes.
* adj: an array of v vectors which represents the neighbors of nodes.
*/

class Graph{
    
    int v;
    vector<int>* adj;
    
    public:
    
    Graph(int v){
        this->v = v;
        adj = new vector<int>[v];
    }
    
    // add edge between u and v
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    
    // get nodes number
    int getV(){
        return v;
    }
    
    // get neighbors of v
    vector<int>& getNeighbors(int v){
        return adj[v];
    }
};

// DFS graph g starting with node w 
void dfsUtil(Graph& g, int w, bool* visited){
    visited[w] = true;
    vector<int>& w_adj = g.getNeighbors(w);
    for(int i = 0; i < w_adj.size(); i++){
        if(visited[w_adj[i]] == false){
            dfsUtil(g, w_adj[i], visited);
        }
    }
}

// Check if there is a route from src to dest.
bool ifConnected(Graph& g, int src, int dest){
    int v = g.getV();
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    dfsUtil(g, src, visited);
    return visited[dest];
}

// Check if there is a route between u and v.
bool isRouteExist(Graph& g, int u, int v){
    return (ifConnected(g, u, v) || ifConnected(g, v, u));
}

// Print graph g
void printGraph(Graph& g){
    int v = g.getV();
    for (int i = 0; i < v; i++) { 
        cout << "Neighbors of " << i << ": ";
        vector<int>& i_adj = g.getNeighbors(i);
        for (auto x : i_adj) 
           cout << x << " ";
        cout << endl;
    } 
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(3,6);
    printGraph(g);
    if(isRouteExist(g, 6, 0)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
