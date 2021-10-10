/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size())
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rowToLook = 0;
        for(int row=0;row<m;row++){
            cout << matrix[row][0] << "\t" << matrix[row][n-1] << endl;
                if(matrix[row][n-1] < target)
                    continue;
                else if(matrix[row][0] == target || matrix[row][n-1] == target)
                    return true;
                else if(matrix[row][0] < target && target < matrix[row][n-1]) {
                    rowToLook = row;
                    break;
                }
        }
        
        cout << rowToLook << endl;
        for(int i=0;i<=rowToLook;i++) {
            for(int j=1;j<n-1;j++) {
                cout << matrix[i][j] << endl;
                 if(matrix[i][j] == target)
                     return true;
            }
        }

        return false;  
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60},{70,90,98,100}
    };
    int target = 30;
    Solution sol;
    cout << boolalpha << sol.searchMatrix(matrix,target) << endl;
    return 0;
}