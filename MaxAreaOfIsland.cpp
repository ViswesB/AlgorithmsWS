/*
695. Max Area of Island
Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    int dfsGrid(vector<vector<int>>& grid,int r,int c) {
        int maxRow = grid.size();
        int maxCol = grid[0].size();
        
        // ISLAND MEANS we are looking for 1. Anything other than 1 
        // is water or not considered as land
        if(r < 0 || c < 0 || r >= maxRow || c >= maxCol || grid[r][c] != 1)
            return 0;
        
        //visited node is set to 2 (not 0 or 1)
        //to save space on using additional grid of size m*n
        grid[r][c] = 2;
        
        // calculate for up/down/left/right
        return (1 + 
                dfsGrid(grid,r-1,c) +
                dfsGrid(grid,r+1,c) +
                dfsGrid(grid,r,c-1) +
                dfsGrid(grid,r,c+1)
               );
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1)
                    maxArea = max(dfsGrid(grid,i,j),maxArea);
            }
        }
        return maxArea;
    }
};

int main() {
    shared_ptr<Solution> sol = make_shared<Solution>();
    vector<vector<int>> grid = 
    {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << sol->maxAreaOfIsland(grid) << endl;
    return 0;
}