/*
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> rank;
public:
    void constructvector(int arraySize) {
        root.resize(arraySize);
        rank.resize(arraySize);
        for(int i=0;i<arraySize;i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    //find parent of a node
    int find(int x) {
        while(x != root[x]) {
            x = root[x];
            //path compression , where we are updating
            //while finding a root to that of its grand parent
            root[x] = root[root[x]];
        }
        return root[x];
    }
    
    //union of 2 nodes
    int unionSet(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)
            return 0;
        
        //always connect smaller tree to bigger tree
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        else {
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
        
        return 1;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        constructvector(n);
        int rows = n;
        int cols = isConnected[0].size();
        int result = n; // number of nodes/vertices
        
        //idea is to start with we will have n number of nodes/vertices
        //while performing union, we will have 2 nodes connected which means
        //number of nodes left unconnected will be number of nodes - union'ed nodes
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(i == j){
                    //node connected to itself
                    // marking as visited
                    isConnected[i][j] = 0;
                    continue;
                }
                
                if(isConnected[i][j]) {
                    result -= unionSet(i,j);
                }
            }
        }
        return result;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    vector<vector<int>> nums = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol->findCircleNum(nums) << endl;
    return 0;
}