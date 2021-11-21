/*
Optimize Water Distribution in a Village

Solution
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional.

Return the minimum total cost to supply water to all houses.

 

Example 1:


Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
Example 2:

Input: n = 2, wells = [1,1], pipes = [[1,2,1]]
Output: 2
 

Constraints:

2 <= n <= 104
wells.length == n
0 <= wells[i] <= 105
1 <= pipes.length <= 104
pipes[j].length == 3
1 <= house1j, house2j <= n
0 <= costj <= 105
house1j != house2j
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <memory>
using namespace std;

struct edge {
    int house1;
    int house2;
    int cost;
    edge(int x,int y,int cost) : house1(x),house2(y),cost(cost) {}
};

struct mycomparator {
    bool operator()(const edge& lhs,const edge& rhs) {
        return lhs.cost > rhs.cost;
    }    
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        //when we look at pipes we have a clear house1,house2 and cost of laying pipes
        //but if we look at wells, we are unable to have a edge with wells
        //so bringing an virtual node 0 to bring all into single prim's algorthm nodes
        
        int result = 0;
        int size = wells.size();
        int nEdges = size-1;
        vector<bool> visited(size+1,false); //consider virtual node
        priority_queue<edge,vector<edge>,mycomparator> minHeap;
        vector<list<edge>> adjPipesList(2*(size+1));
        
        //picking 0 as random arbitrary node for prim's
        for(int i=0;i<size;i++) {
            minHeap.push(edge(0,i+1,wells[i]));
        }
        visited[0] = true;
        
        //create unordered_map b/w starting node and its edges from pipes
        for(int i=0;i<pipes.size();i++) {
            adjPipesList[pipes[i][0]].push_front(edge(pipes[i][0],pipes[i][1],pipes[i][2]));
            adjPipesList[pipes[i][1]].push_front(edge(pipes[i][1],pipes[i][0],pipes[i][2]));
        }
        
        while(!minHeap.empty()) {
            auto tempEdge = minHeap.top();
            minHeap.pop();
            
            if(visited[tempEdge.house2])
                continue;
            
            result += tempEdge.cost;
            int nextHouse = tempEdge.house2;
            visited[nextHouse] = true;
            
            //find edge from list
            if(adjPipesList[nextHouse].size() == 0)
                continue;
            
            for(auto adjEdges: adjPipesList[nextHouse]) {
                    minHeap.push(adjEdges);
            }
        }
        
        return result;
    }
};

int main() {
    int n = 3;
    vector<int> wells = {1,2,2};
    vector<vector<int>> pipes = {{1,2,1},{2,3,1}};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->minCostToSupplyWater(n,wells,pipes);
    return 0;
}