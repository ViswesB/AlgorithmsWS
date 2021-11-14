/*
All Paths from Source Lead to Destination

Solution
Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes ai and bi, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually, end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.
Example 2:


Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.
Example 3:


Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true
Example 4:


Input: n = 3, edges = [[0,1],[1,1],[1,2]], source = 0, destination = 2
Output: false
Explanation: All paths from the source node end at the destination node, but there are an infinite number of paths, such as 0-1-2, 0-1-1-2, 0-1-1-1-2, 0-1-1-1-1-2, and so on.
Example 5:


Input: n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
Output: false
Explanation: There is infinite self-loop at destination node.
 

Constraints:

1 <= n <= 104
0 <= edges.length <= 104
edges.length == 2
0 <= ai, bi <= n - 1
0 <= source <= n - 1
0 <= destination <= n - 1
The given graph may have self-loops and parallel edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<list<int>> adjList;
    vector<bool> visited; // to denote path lead to DESTINATION
    vector<bool> visiting; // to denote path in search of DESTINATION. avoid loops
    void init(int n) {
        adjList.resize(n);
        visited.resize(n);
        visiting.resize(n);
    }
    
    bool dfs(int source,int destination) {
        bool retVal = false;
        
        //will this path lead to destination
        if(visited[source])
            return true;
        
        //no neighbors for this node, verify if we reached destination or not
        if(adjList[source].size()==0)
            return source == destination;
        
        //are we in loop ?, yes return false
        if(visiting[source])
            return false;
        
        //visiting for first time
        visiting[source] = true;
        
        //checkout neighbors
        for(auto itr=adjList[source].begin();itr!=adjList[source].end();itr++) {
            retVal = dfs(*itr,destination);
            if(retVal == false)
               return retVal;
        }
        
        //store result of this path to true as this lead us to destination
        visited[source] = retVal;
        return retVal;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        //create adjList
        for(auto edge:edges) {
             adjList[edge[0]].push_front(edge[1]);
        }
        
        return dfs(source,destination);
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    //n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
    // n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
    // n = 5 edges = [[0,1],[0,2],[0,3],[0,3],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]] source = 0 destination = 4
    int n = 5;
    int source = 0;
    int destination = 4;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {0,3},
        {0,3},
        {1,2},
        {1,3},
        {1,4},
        {2,3},
        {2,4},
        {3,4}
    };
    cout << boolalpha << sol->leadsToDestination(n,edges,source,destination) << endl;
    return 0;
}