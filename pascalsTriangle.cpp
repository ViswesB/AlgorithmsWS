/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 https://leetcode.com/problems/pascals-triangle/

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    1 <= numRows <= 30

*/
#include <iostream>
#include <vector>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateOld(int numRows) {
        vector<vector<int>> vecOfVec;
        // numRows will be b/w 1 to 30
        if(numRows <= 0 || numRows > 30)
            return vecOfVec;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> vec;
            vector<int> readVec;
            if(vecOfVec.size()) {
                readVec = vecOfVec[i-1]; //TODO
            }
            else if(vecOfVec.size() == 0) {
                vec.push_back(1);
                vecOfVec.push_back(vec);
                continue;
            }
            //array creation size should be size of vector + 1
            auto sze = readVec.size() + 1;

            for(int j=0;j<sze;j++)
            {
                //Fill First element and Last Element as 1
                if(j==0 || j==sze-1)
                    vec.push_back(1);
                else {
                    vec.push_back(readVec[j-1] + readVec[j]);
                }
            }
            vecOfVec.push_back(vec);
        }
        return vecOfVec;
    }

    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {{}};
        
        vector<vector<int>> matVec;
        vector<int> row;
        for(int i=0;i<numRows;i++) {
            //for first row it will be 1
            if(i==0) 
                row.push_back(1);
            else if(i==1) {
                row.push_back(1);
                row.push_back(1);
            }
            else {
                //pick the above row
                auto rowAbove = matVec[i-1];
                //construct this row by calculating
                row.resize(rowAbove.size()+1);
                row[0] = 1;
                for(int j=0;j < rowAbove.size()-1;j++) {
                    row[j+1] = rowAbove[j] + rowAbove[j+1];
                }
                row[row.size()-1] = 1;
            }
            
            matVec.push_back(row);
            row.clear();
        }
        return matVec;
    }
};

int main()
{
    int n = 5;
    Solution sol;
    auto completeVec = sol.generate(n);
    // vector<int> v2 = {4,5,6};
    for(auto& i:completeVec)
    {
        for(auto& j:i)
        {
           cout << j << "\t";
        //    completeVec.push_back(v2);
        }
        cout << endl;
    }
    return 0;
}