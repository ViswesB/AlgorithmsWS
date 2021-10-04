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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> cVec;
        if (numRows < 1 || numRows > 30)
            return cVec;

        vector<int> firstRow = {1};
        vector<int> tempRow;
        int count = 1;
        int rowSize = 0;
        while(numRows != count)
        {
            cVec.push_back(firstRow);
            //cout << "complete vector size:" << cVec.size() << endl;
            // for(auto i:firstRow)
            //     cout << i << endl;
            rowSize += 1;
            for(int i=0;i<firstRow.size();i++)
            {
                // cout << "Print i:" << i << endl;
                tempRow.push_back(1);
                if(i != rowSize && i != 0) {
                    //add top row elements
                    tempRow[i] = tempRow[i-1] + tempRow[i];
                }
                 for(auto j:tempRow)
                    cout << j << endl;
                // else if(i == rowSize)
                // {
                //     // push to complete vector
                //     cVec.push_back(firstRow);
                // }
            }
            firstRow = tempRow;
            
            count++;
        }
        return cVec;
    }
};

int main()
{
    int n = 5;
    Solution sol;
    auto completeVec = sol.generate(n);
    vector<int> v2 = {4,5,6};
    for(auto& i:completeVec)
    {
        for(auto& j:i)
        {
           cout << j << endl;
           completeVec.push_back(v2);
        }
    }
    return 0;
}