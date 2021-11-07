/*
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> rank;
public:
    void constructvector(int nodes) {
        root.resize(nodes);
        rank.resize(nodes);
        for(int i=0;i<nodes;i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    //find root of node x
    int find(int x) {
        while(x != root[x]) {
            x = root[x];
            //path compression
            root[x] = root[root[x]]; //to grand parent
        }
        return root[x];
    }
    
    int unionset(int x,int y) {
        //find parent of x and y
        int rootX = find(x);
        int rootY = find(y);
        
        //already connected
        if(rootX == rootY)
            return 0;
        
        //join based on rank(weight)
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
            //update weight to rootX + rootY
            rank[rootX] += rank[rootY];
        }
        else {
            root[rootX] = rootY;
            //update weight
            rank[rootY] += rank[rootX];
        }
        
        //connected 2 nodes to one edge
        return 1;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return 1;
        
        int result = n;
        constructvector(n);
        for(int i=0;i<edges.size();i++) {
            result -= unionset(edges[i][0],edges[i][1]);
        }
        
        return result;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    int n = 5;
    vector<vector<int>> nums = {{0,1},{1,2},{3,4}};
    cout << sol->countComponents(n,nums) << endl;
    return 0;
}