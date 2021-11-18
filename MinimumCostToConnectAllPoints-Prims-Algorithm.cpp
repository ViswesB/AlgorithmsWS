    /*

Minimum Cost to Connect All points - PRIMS algorithm

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4

Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000

Example 5:

Input: points = [[0,0]]
Output: 0

 

Constraints:

    1 <= points.length <= 1000
    -106 <= xi, yi <= 106
    All pairs (xi, yi) are distinct.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

struct edge {
    int x;
    int y;
    int cost;
    edge(int x,int y, int cost) : x(x), y(y), cost(cost) {}
};

struct mycomparator {
    bool operator()(const edge& lhs, const edge& rhs) {
        return lhs.cost > rhs.cost;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        if(size==0)
            return 0;

        int result = 0;
        //Prim's algorithm works on nodes while kruskal's work on edges
        int nEdges = size-1;

        //Prim's algorithm would start on random node
        //here we are picking 0
        priority_queue<edge,vector<edge>,mycomparator> minHeap;

        //keep track of visited
        vector<bool> visited(size,false);

        for(int i=1;i<size;i++) {
            //calculate cost from 0 node to other nodes
            int cost = abs(points[0][0] - points[i][0]) +
                        abs(points[0][1] - points[i][1]);
            minHeap.push(edge(0,i,cost));
        }
        visited[0] = true;

        while(!minHeap.empty() && nEdges > 0) {
            auto topEdge = minHeap.top();
            minHeap.pop();
            int nextNode = topEdge.y;

            if(visited[nextNode])
                continue;
            
            result += topEdge.cost;
            visited[nextNode] = true;
            //Heapify edges for nextNode
            for(int i=0;i<size;i++) {
                int cost = abs(points[nextNode][0] - points[i][0]) +
                            abs(points[nextNode][1] - points[i][1]);
                minHeap.push(edge(nextNode,i,cost));
            }
            nEdges--;
        }

        return result;
    }
};


int main() {
    vector<vector<int>> points = {{-8,14},{16,-18},{-19,-13},{-18,19},{20,20},{13,-20},{-15,9},{-4,-8}};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->minCostConnectPoints(points) << endl;
    return 0;
}