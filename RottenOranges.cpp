/*
Rotten Oranges
994. Rotting Oranges
Medium

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

Accepted
298,686
Submissions
584,532
*/

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

class Solution {
    bool isValid(int i,int j,int rows,int cols,const vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i > rows-1 || j > cols-1)
            return false;
        if((grid[i][j] == 0) || (grid[i][j] == 2))
            return false;
        return true;
    }
    
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    
    struct location {
        int x;
        int y;
        int min;
        location(int p,int q,int m) : x(p),y(q),min(m) {}
    };
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<location> qGrid;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxMins = -1;
        int freshOranges = 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++)
            if(grid[i][j] == 2)
                qGrid.push(location(i,j,0));
            else if(grid[i][j] == 1)
                freshOranges++;
        }
        
        if(freshOranges == 0)
            return 0;
        
        while(!qGrid.empty()) {
            location loc = qGrid.front();
            qGrid.pop();
            int nX = loc.x;
            int nY = loc.y;
            maxMins = loc.min;
            
            //go in 4 directions
            for(auto direction: directions) {
                if(isValid(nX+direction[0],nY+direction[1],rows,cols,grid)) {
                    qGrid.push(location(nX+direction[0],nY+direction[1],maxMins+1));
                    //mark rotten
                    grid[nX+direction[0]][nY+direction[1]] = 2;
                    freshOranges--;
                }
            }
        }
        
        if(freshOranges!=0)
            return -1;
        
        return maxMins;
    }
};

int main() {
    // vector<vector<int>> grid = {
    //     {2,1,1},
    //     {1,1,0},
    //     {0,1,1}
    // };
    vector<vector<int>> grid = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->orangesRotting(grid) << endl;
    return 0;
}