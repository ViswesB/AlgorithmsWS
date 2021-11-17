/*
Minimum Cost to Connect All points - KRUSKAL

ou are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

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
#include <memory>
#include <queue>
using namespace std;

class unionfind {
    vector<int> root;
    vector<int> rank; //weight
public:
    unionfind(int size) {
        root.reserve(size);
        rank.reserve(size);
        for(int i=0;i<size;i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    bool connected(int x,int y) {
        return find(x) == find(y);
    }
    
    //find parent of x
    int find(int x) {
        while(x != root[x]) {
            x = root[x];
            //path compression
            root[x] = root[root[x]];
        }
        
        return root[x];
    }
    
    void unionset(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        //parent of both x and y to be same
        //avoid forming a loop. return
        if(rootX == rootY)
            return;
        
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        else {
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
};

struct edge {
    int x;
    int y;
    int cost;
    edge(int x,int y,int cost) : x(x),y(y),cost(cost) {}
};

struct mycomparator {
    bool operator()(const edge& lhs,const edge& rhs) {
        return lhs.cost > rhs.cost;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        
        //min cost
        int result = 0;
        
        //total size;
        int size = points.size();
        
        //kruskal need n-1 nodes for MST
        int kedges = size-1;
        
        //idea is to use priority queue
        priority_queue<edge,vector<edge>,mycomparator> minHeap;
        
        //initialize union
        unionfind uf(size);
        
        //find cost of all edges and push to min heap (heapify)
        //example (0th node connected to 1st node where cost is x) ==> (0,1,x)
        for(int i=0;i<size;i++) {
            vector<int> pointA = points[i];
            for(int j=i+1;j<size;j++) {
                vector<int> pointB = points[j];
                //find cost
                int cost = abs(pointA[0]- pointB[0]) + abs(pointA[1] - pointB[1]);
                minHeap.push(edge(i,j,cost));
            }
        }
        
        //go through heap and union nodes
        //union find coded to avoid loop
        while(!minHeap.empty() && kedges > 0) {
            auto tempEdge = minHeap.top();
            minHeap.pop();
            //union nodes
            if(!uf.connected(tempEdge.x,tempEdge.y)) {
                uf.unionset(tempEdge.x,tempEdge.y);
                result += tempEdge.cost;
                kedges--;
            }
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