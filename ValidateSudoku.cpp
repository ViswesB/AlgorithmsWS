/*
36. Valid Sudoku
Medium

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

 

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

 

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit 1-9 or '.'.

*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    char delim = '.';
public:
    void printSet(unordered_set<string> uoChar) {
        for(auto itr=uoChar.begin(); itr != uoChar.end(); itr++)
            cout << *itr << "\t" << endl;
        cout << endl;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> uoChar;
        string rStr = "Row";
        string cStr = "Col";
        string subBoxStr = "SubBox";
        for(int row=0;row<9;row++) {
            for(int col=0;col<9;col++) {
                if(board[row][col] == '.')
                    continue;
                
                string strRow = to_string(board[row][col]) + "_" + rStr + "_" + to_string(row);
                string strCol = to_string(board[row][col]) + "_" + cStr + "_" + to_string(col);
                string strSubBox = to_string(board[row][col]) + "_" + subBoxStr + "_" + to_string(row/3)+ to_string(col/3);

                if(uoChar.end() == uoChar.find(strRow))
                    uoChar.insert(strRow);
                else {
                    cout << "for Row: " << strRow << endl;
                    printSet(uoChar);
                    return false;
                }

                if(uoChar.end() == uoChar.find(strCol))
                    uoChar.insert(strCol);
                else {
                    cout << "for cold: " << strCol << endl;
                    printSet(uoChar);
                    return false;
                }
                
                if(uoChar.end() == uoChar.find(strSubBox))
                    uoChar.insert(strSubBox);
                else {
                    // cout << "for subbox: " << strSubBox << endl;
                    printSet(uoChar);
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','4'}
    };
    cout << "row size: " << board[0].size() << endl;
    cout << "col size: " << board.size() / board[0].size() << endl;
    Solution sol;
    cout << boolalpha << sol.isValidSudoku(board) << endl;
    return 0;
}