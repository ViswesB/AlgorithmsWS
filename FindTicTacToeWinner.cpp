/*
Find Winner on a Tic Tac Toe Game

Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

    Players take turns placing characters into empty squares (" ").
    The first player A always places "X" characters, while the second player B always places "O" characters.
    "X" and "O" characters are always placed into empty squares, never on filled ones.
    The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.

Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

 

Example 1:

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"

Example 2:

Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "

Example 3:

Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"

Example 4:

Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
"X  "
" O "
"   "

 

Constraints:

    1 <= moves.length <= 9
    moves[i].length == 2
    0 <= moves[i][j] <= 2
    There are no repeated elements on moves.
    moves follow the rules of tic tac toe.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string A_WINS = "A";
const string B_WINS = "B";
const string DRAW = "Draw";
const string PENDING = "Pending";
const char PLAYERA_MARK = 'X';
const char PLAYERB_MARK = 'O';

class Solution {
public:
    char whoseTurn(int i)
    {
        char player;
        if (i%2 == 0)
            player = 'X';
        else
            player = 'O';
        return player;
    }

    string tictactoe(vector<vector<int>>& moves) {
        string result = PENDING;
        if(moves.size() == 0 || moves.size() > 9)
            return result;
        
        gameBoard = {"   ", "   " , "   "};
        /*
               012
            0 "   "
            1 "   "
            2 "   "
        */   
        for(int i=0;i<moves.size();i++)
        {
            auto tmpVec = moves.at(i);
            if(tmpVec.size() < 2 || tmpVec.size() > 2)
                return result;
            gameBoard[tmpVec[0]][tmpVec[1]] = whoseTurn(i);
        }

        result = AnalyzeDiagonal();
        if(result.compare("") == 0) {
            result = AnalyzeRow_Columns();
            if(result.compare("") == 0)
            {
                if(moves.size() == 9)
                    result = DRAW;
                else
                    result = PENDING;
            }
        }

        return result;
    }

    string AnalyzeRow_Columns()
    {
        string ret;
        for(int row=0;row<gameBoard.size();row++)
        {
            if((gameBoard[row][0] == gameBoard[row][1]) && (gameBoard[row][1] == gameBoard[row][2]))
            {
                if(gameBoard[row][0] == PLAYERA_MARK)
                    ret = A_WINS;
                else if(gameBoard[row][0] == PLAYERB_MARK)
                    ret = B_WINS;
            }
            else if((gameBoard[0][row] == gameBoard[1][row]) && (gameBoard[1][row] == gameBoard[2][row]))
            {
                if(gameBoard[0][row] == PLAYERA_MARK)
                    ret = A_WINS;
                else if(gameBoard[0][row] == PLAYERB_MARK)
                    ret = B_WINS;
            }
        }
        return ret;
    }

    string AnalyzeDiagonal()
    {
        string ret;
        if ((gameBoard[0][0] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[2][2]) ||
            (gameBoard[0][2] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[2][0]))
        {
            if (gameBoard[1][1] == PLAYERA_MARK)
                ret = A_WINS;
            else if (gameBoard[1][1] == PLAYERB_MARK)
                ret = B_WINS;
        }
        return ret;
    }

    void printGameBoard()
    {
        for(auto itr=gameBoard.begin();itr!=gameBoard.end();itr++)
            cout << *itr << endl;
    }
private:
    vector<string> gameBoard;
};

int main()
{
    // vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    // vector<vector<int>> moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    // vector<vector<int>> moves = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    // vector<vector<int>> moves = {{2,0},{1,1},{0,2},{2,1},{1,2},{1,0},{0,0},{0,1}};
    // vector<vector<int>> moves = {{0,0},{1,1}};
    vector<vector<int>> moves = {{1,0},{2,0},{0,1}};
    Solution sol;
    auto whoWon = sol.tictactoe(moves);
    sol.printGameBoard();
    cout << "Who Won ?? " << whoWon << endl;
    return 0;
}