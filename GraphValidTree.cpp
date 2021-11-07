/*
 Graph Valid Tree

Solution
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> rank;
public:
    void constructVector(int n) {
        root.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x) {
        while(x != root[x]) {
            x = root[x];
            //path compression
            root[x] = root[root[x]];
        }
        
        return root[x];
    }
    
    int unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY)
            return 0;
        
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        else {
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
        
        return 1;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //if graph is a tree then for n nodes, there will be n-1 edges
        //more edges mean circular graph
        // tree wont have circular edges
        if(edges.size() > n-1)
            return false;
        
        int connectedNodes = n;
        constructVector(n);
        
        for(int i=0;i<edges.size();i++) {
            connectedNodes -= unionSet(edges[i][0],edges[i][1]);
        }
        
        //at the end there should be only one connected component or circle
        //else graph is not complete
        return connectedNodes == 1;
    }
};

int main() {
    int n = 5;
    // vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << boolalpha << sol->validTree(n,edges) << endl;
    return 0;
}