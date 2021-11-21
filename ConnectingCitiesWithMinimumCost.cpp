/*
Connecting cities with minimum cost
1135. Connecting Cities With Minimum Cost
Medium

738

40

Add to List

Share
There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.

 

Example 1:


Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:


Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
 

Constraints:

1 <= n <= 104
1 <= connections.length <= 104
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 105
Accepted
44,925
Submissions
74,715
*/

#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <list>
using namespace std;

struct connect {
    int city1;
    int city2;
    int cost;
    connect(int city1,int city2,int cost) : city1(city1),city2(city2),cost(cost) {}
};

struct mycomparator {
    bool operator() (const connect& lhs,const connect& rhs) {
        return lhs.cost > rhs.cost;
    }    
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        //using prim's algo
        //priority queue for min_heap
        priority_queue<connect,vector<connect>,mycomparator> minHeap;
        //visited
        vector<bool> visited(n+1,false);
        //adjacency list
        vector<list<connect>> adjacencyList(n+1);
        
        int nEdges = n-1;
        int result = 0;
        
        for(auto connection: connections) {
           adjacencyList[connection[0]].push_front
               (connect(connection[0],connection[1],connection[2]));
           adjacencyList[connection[1]].push_front
               (connect(connection[1],connection[0],connection[2]));
        }
        
        //heapify from any arbitrary node so picking 1
        for(auto adj: adjacencyList[1]) {
            minHeap.push(adj);
        }
        visited[1] = true;
        
        while(!minHeap.empty() && nEdges > 0) {
            auto tempConnection = minHeap.top();
            minHeap.pop();
            if(visited[tempConnection.city2])
                continue;
            
            visited[tempConnection.city2] = true;
            result += tempConnection.cost;
            int nextCity = tempConnection.city2;
            for(auto adj: adjacencyList[nextCity]) {
                minHeap.push(adj);
            }    
            nEdges--;
        }
        
        if(nEdges > 0)
            return -1;
        return result;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> connections = {
       {1,2,5},
       {1,3,6},
       {2,3,1}
    };
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->minimumCost(n,connections) << endl;
    return 0;
}