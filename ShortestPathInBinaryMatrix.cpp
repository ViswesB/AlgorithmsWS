/*
1091. Shortest Path in Binary Matrix
Medium

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <memory>
using namespace std;

class Solution {
    struct node {
        int p;
        int q;
        int cost;
        node(int x,int y,int c): p(x), q(y), cost(c) {}
    };
    
    bool isDirectionValid(int i,int j,int rows,int cols,vector<vector<int>>& grid) {
        if(i < 0 || j < 0  || i > rows-1 || j > cols-1)
            return false;
        if(grid[i][j] == 1)
            return false;
        return true;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<node> qMatrix;
        vector<vector<int>> directions = {{1,1},{0,1},{1,0},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        
        if((grid[0][0] == 1) || (grid[rows-1][cols-1] == 1))
            return -1;
        
        qMatrix.push(node(0,0,1));
        
        grid[0][0] = 1;
        int len = 1;
        
        while(!qMatrix.empty()) {
            auto elem = qMatrix.front();
            int i = elem.p;
            int j = elem.q;
            int len = elem.cost;
            
            qMatrix.pop();            
                        
            if(i == rows-1 && j == cols-1)
                return len;
            
            //verify all 8 directions
            for(auto direction: directions) {
                int x = i + direction[0];
                int y = j + direction[1];
                if(isDirectionValid(x,y,rows,cols,grid)) {
                    qMatrix.push(node(x,y,len+1));
                    //mark visited
                    grid[x][y] = 1;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    vector<vector<int>> grid = {
        {0,0,0,0,1},
        {1,0,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,1},
        {0,0,0,1,0}
    };
    //if -1 no path available
    cout << sol->shortestPathBinaryMatrix(grid) << endl;
    return 0;
}