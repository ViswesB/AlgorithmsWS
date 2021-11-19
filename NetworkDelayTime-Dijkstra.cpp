/*
743. Network Delay Time
Medium

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

 

Constraints:

    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <iostream>
#include <unordered_set>
#include <list>
#include <queue>
#include <memory>
using namespace std;

struct edge {
    int source;
    int target;
    int cost;
    edge(int s,int t,int c): source(s),target(t),cost(c) {}
};

struct mycomparator {
    bool operator()(const edge& lhs,const edge& rhs) {
        return lhs.cost > rhs.cost;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //use adjacency list for all nodes
        vector<list<edge>> adjList(n+1);
        for(auto time:times)
            adjList[time[0]].push_front(edge(time[0],time[1],time[2]));
        
        //priority queue minHeap
        priority_queue<edge,vector<edge>,mycomparator> minHeap;

        //hashset to keep track of visited nodes
        unordered_set<int> visitedNodes(n);

        //start with k node
        minHeap.push(edge(k,k,0));

        int result = INT_MIN;

        while(!minHeap.empty()) {
            auto tempEdge = minHeap.top();
            minHeap.pop();

            if(visitedNodes.end() != visitedNodes.find(tempEdge.target))
                continue;

            visitedNodes.insert(tempEdge.target);
            result = max(result,tempEdge.cost);

            //move to next node
            for(auto targetNode: adjList[tempEdge.target]) {
                if(visitedNodes.end() == visitedNodes.find(targetNode.target))
                    minHeap.push(edge(targetNode.source,targetNode.target,targetNode.cost + tempEdge.cost));
            }
        }

        return (visitedNodes.size()==n) ? result : -1;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    int n = 3;
    int k = 1;
    vector<vector<int>> times = {
        {1,2,1},
        {2,3,2},
        {1,3,4}
    };
    cout << sol->networkDelayTime(times,n,k) << endl;
    return 0;
}