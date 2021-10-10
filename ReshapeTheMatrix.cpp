/*
566. Reshape the Matrix
Easy

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Example 2:

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    -1000 <= mat[i][j] <= 1000
    1 <= r, c <= 300

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // Get number elements in matrix
        size_t noOfElemInMatrix = 0;
        for(auto itr=mat.begin(); itr!=mat.end();itr++) {
            noOfElemInMatrix += (*itr).size();
        }

        cout << noOfElemInMatrix << endl;
        // If requested row and col elements are more than what we have return original matrix
        if((r * c) != noOfElemInMatrix)
            return mat;
        
        // check if original r and c are same as requested
        vector<vector<int>> resizeMat;
        vector<int> tempVec;

        auto itr = mat.begin();
        while(itr!=mat.end()) {
            for(auto i:*itr) {
                tempVec.push_back(i);
                    if(tempVec.size() == c) {
                        resizeMat.push_back(tempVec);
                        tempVec.clear();
                    }
            }
            itr++;
        }
        
        return resizeMat;
    }
};

int main () {
    Solution sol;
    // vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // vector<vector<int>> mat = {{1,2}, {3,4}};
    vector<vector<int>> mat = {{1,2}};

    
    int row = 1;
    int col = 4;
    auto resMatrix = sol.matrixReshape(mat, 1 ,1);
    cout << resMatrix.size() << endl;
    // checks after resize matrix
    if(resMatrix.size() != row)
        cout << "resized matrix not having same rows are expected in r" << endl;

    for(auto itr=resMatrix.begin();itr!=resMatrix.end();itr++) {
        for (auto i : *itr) 
            cout << i << "\t" ;
        cout << endl;
    }
    return 0;
}