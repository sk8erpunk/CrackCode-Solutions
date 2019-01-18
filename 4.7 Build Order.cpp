/******************************************************************************
Build Order
You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.
EXAMPLE
Input:
projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output: f, e, a, b, d, c
*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Graph {
	private:
	list<char> nodes;                           // nodes
	unordered_map<char,list<char>> edges;       // edges
	unordered_map<char,int> countDependencies;  // incoming edges count
	
    public:	
	Graph(){}
	void addNode(char c){
		nodes.push_back(c);
		countDependencies[c] = 0;
	}
	void addEdge(char c1, char c2){
		edges[c1].push_back(c2);
		incrementDependencies(c2);
	}
	list<char>& getEdges(char c){
		return edges[c];
	}
	void decrementDependencies(char c){
	    countDependencies[c]--;
	}
	void incrementDependencies(char c){
	    countDependencies[c]++;
	}
	int getCountDependencies(char c){
	    return countDependencies[c];
	}
};

// Time complexity is O(V+E) where V is number of projects and E is number of dependencies
void buildGraph(Graph* g, list<char>& projects, list<pair<char,char>>& dependencies){
	for(auto& p : projects) {
		g->addNode(p);
	}
	for(auto& p: dependencies){
		g->addEdge(p.first, p.second);
	}
}

// Time complexity is O(V)
int findUndependent(Graph* g, vector<char>& order, list<char>& projects, int ofst){
	for(auto& p : projects){
		if(g->getCountDependencies(p) == 0){
			order[ofst] = p;
			ofst++;
		}
	}
	return ofst;
}

// Time complexity is O(V+E)
// Memory space is O(V+E) (used graph)
vector<char> buildOrder(list<char> projects, list<pair<char,char>> dependencies){
	
	// build graph O(V+E)
	Graph* g = new Graph();
	buildGraph(g, projects, dependencies);
	
	// result array
	vector<char> order(projects.size(),'#');
	
	// find non dependant projects O(V)
	int currProjectIdx = 0;
	int end = findUndependent(g, order, projects, currProjectIdx);
	
	// As long as there a non dependant project
	// This loop is O(V+E) because we visit each node and edge once
 	while(currProjectIdx < order.size()){
 		char currProject = order[currProjectIdx];
 		
 		// no more non dependant
 		if(currProject == '#')
 		    throw "Error! no such order exist!";
		
		// decrement counts from children
 		list<char>& children = g->getEdges(currProject);
 		for(auto& child : children){
			g->decrementDependencies(child); 
 		}
 		
 		// add new non dependant nodes 
 		end = findUndependent(g, order, children, end);
 		
		currProjectIdx++;
 	}
	return order;
}


int main() {
    
    char names[] = {'a','b','c','d','e','f','g'};
    list<char> projects (names, names + sizeof(names) / sizeof(char));
    list<pair<char,char>> dependencies;
    dependencies.push_back(make_pair('f','c'));
    dependencies.push_back(make_pair('f','b'));
    dependencies.push_back(make_pair('b','a'));
    dependencies.push_back(make_pair('f','a'));
    dependencies.push_back(make_pair('c','a'));
    dependencies.push_back(make_pair('a','e'));
    dependencies.push_back(make_pair('d','g'));
    vector<char> res = buildOrder(projects,dependencies);
    
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "->";
        
    return 0;
}