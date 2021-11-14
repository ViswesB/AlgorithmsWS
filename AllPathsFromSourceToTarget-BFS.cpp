/*
All paths from source to target
 All Paths From Source to Target

Solution
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

#include <iostream>
#include <queue>
#include <vector>
#include <memory>
#include <list>
using namespace std;

class Solution {
private:
    queue<vector<int>> q;
    vector<vector<int>> bfs(int start,int end,vector<list<int>>& adjList) {
        vector<int> path;
        vector<vector<int>> paths;
        
        q.push({start});
        // visited[start] = true;
        path.emplace_back(start);
        
        while(!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            
            //check last element if its dest then push to paths
            int lastElem = *(path.end()-1);
            if(end == lastElem)
                paths.emplace_back(path);
            else {
                //look into adjacency list of last element
                for(auto itr=adjList[lastElem].begin();itr!=adjList[lastElem].end();itr++) {
                    path.push_back(*itr);
                    q.push(path);
                    //remove last element
                    path.pop_back();
                }
            }
        }
        
        return paths;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size()==0)
            return {{}};
        
        int n = graph.size();
        //init
        vector<list<int>> adjList(n);
        
        //create adjacency list
        for(int i=0;i<n;i++) {
            for(auto itr=graph[i].begin();itr!=graph[i].end();itr++) {
                adjList[i].push_front(*itr);   
            }
        }
        
        //perform bfs
        return bfs(0,n-1,adjList);
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