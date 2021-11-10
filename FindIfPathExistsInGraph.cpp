/*

*/
#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;

class Solution {
private:
    vector<list<int>> adjList;
    vector<bool> visited;
public:
    void init(int n) {
        adjList.resize(n);
        visited.resize(n);
    }
    
    void updateAdjacencyList(int node,int adjNode) {
        adjList[node].push_front(adjNode);
        adjList[adjNode].push_front(node);
    }
    
    bool dfs(int start,int end) {
        if(start == end)
            return true;
        
        //mark start node as visited
        visited[start] = true;
        
        for(auto itr=adjList[start].begin();itr!=adjList[start].end();itr++) {
            if(!visited[*itr]) {
                bool ret = dfs(*itr,end);
                if(ret)
                    return ret;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(edges.size() == 0)
            return true;
        
        init(n);
        
        for(auto itr=edges.begin();itr!=edges.end();itr++) {
            auto vec = *itr;
            updateAdjacencyList(vec[0],vec[1]);
        }    
        
        return dfs(start,end);
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int start = 0, end = 2;
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << boolalpha << sol->validPath(n,edges,start,end) << endl;
    return 0;
}