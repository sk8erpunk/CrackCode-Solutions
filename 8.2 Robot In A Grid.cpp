/******************************************************************************
Robot in a Grid
Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
The robot can only move in two directions, right and down, but certain cells are "off limits" such that
the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
the bottom right.
*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <boost/functional/hash.hpp>

using namespace std;

typedef pair<int,int> Pair;
typedef unordered_set< Pair , boost::hash<Pair> > HashSet;

bool findPath(vector<vector<int>>& grid, int col, int row, vector<Pair>& path, HashSet& cache){
	if(row < 0 || col < 0 || !grid[row][col])
		return false;
	
	if(cache.count(make_pair(row,col))) // already visited
	    return false;
	    
	bool foundStart = (col == 0 && row == 0);
	
	if(foundStart || findPath(grid, col-1, row, path, cache) ||
		findPath(grid, col, row-1, path, cache)){
		path.push_back(make_pair(row,col));
		return true;
	}
	cache.insert(make_pair(row,col));
	return false;
}

// Time complexity is O(mn)
// Memory space is O(mn)
vector<Pair> findLegalPath(vector<vector<int>>& grid){
    vector<Pair> path;
	if(grid.size() == 0 || grid[0].size() == 0)
	    return path;
	HashSet cache; // caching cells 
	findPath(grid, grid[0].size()-1, grid.size()-1, path, cache);
    return path;
}

int main()
{
    vector<vector<int>> grid {  {1, 1, 1, 0, 0},
                                {0, 1, 1, 1, 0},
                                {1, 1, 0, 0, 1},
                                {1, 1, 1, 1, 1} };
								
	vector<Pair> path = findLegalPath(grid);
	
	// print path 
	for(auto const &p : path)
	    cout << "(" << p.first << "," << p.second << ") ";
	
    return 0;
}
