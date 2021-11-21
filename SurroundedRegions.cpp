/*
130. Surrounded Regions
Medium

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:

Input: board = [["X"]]
Output: [["X"]]

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.

Accepted
367,384
Submissions
1,124,707
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Solution {
    //using dfs change O's on border to 'T'
    void dfs(vector<vector<char>>& board,int i,int j,int rows,int cols) {
        if(i<0 || j<0 || i>rows-1 || j>cols-1 || board[i][j]!='O')
            return;
        
        if(board[i][j] == 'O') {
            board[i][j] = 'T';
        
            // //dfs up/down/left/right to find uncaptured region
            dfs(board,i-1,j,rows,cols);
            dfs(board,i+1,j,rows,cols);
            dfs(board,i,j-1,rows,cols);
            dfs(board,i,j+1,rows,cols);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        //idea is to find the region that is connected to border
        //that region cannot be captured.
        //to simplify that change that to 'T'
        if(board.size()==0)
            return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        //run dfs only on border
        //run on first and last row
        for(int i=0;i<rows;i++) {
            dfs(board,i,0,rows,cols);
            dfs(board,i,cols-1,rows,cols);
        }
        
        //run on first and last col
        for(int i=0;i<cols;i++) {
            dfs(board,0,i,rows,cols);
            dfs(board,rows-1,i,rows,cols);
        }
        
        //go through all elements in grid if it is O -> X
        //if it is T -> O
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                 if(board[i][j] == 'T')
                    board[i][j] = 'O';
                 else
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    vector<vector<char>> board = 
    {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    sol->solve(board);
    for(int i=0;i<board.size();i++) {
        for(int j=0;i<board[0].size();j++) {
            cout << board[i][j] << "\t" ;
        }
        cout << endl;
    }
    return 0;
}