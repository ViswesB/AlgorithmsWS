/*
797. All Paths From Source to Target
Medium

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]

Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]

Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]

 

Constraints:

    n == graph.length
    2 <= n <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i (i.e., there will be no self-loops).
    All the elements of graph[i] are unique.
    The input graph is guaranteed to be a DAG.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<list<int>> adjList;
    vector<int> tempVec;
    vector<vector<int>> retVec;
public:
    void dfs(int source,int dest) {
        tempVec.emplace_back(source);
        
        if(source == dest) {
            retVec.emplace_back(tempVec);
            return;
        }
        
        for(auto itr=adjList[source].begin();itr!=adjList[source].end();itr++) {
            //this is DAG so no loops . No need to keep visited array
            dfs(*itr,dest);
            tempVec.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        adjList.resize(graph.size());
        for(auto i=0;i<graph.size();i++) {
            for(auto j=0;j<graph[i].size();j++) {
                adjList[i].push_front(graph[i][j]);
            }
        }
        
        dfs(0,(graph.size()-1));
        
        return retVec;
    }
};


int main() {
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto paths = sol->allPathsSourceTarget(graph);
    for(auto itr=paths.begin();itr!=paths.end();itr++) {
        for(auto i=itr->begin();i!=itr->end();i++) 
            cout << *i << "\t"; 
        cout << endl;
    }
    return 0;
}