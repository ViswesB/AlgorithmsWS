/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    1 <= numRows <= 30
*/
#include <vector>
#include <iostream>
using namespace std;

const int MAXROWS = 33;
const int MINROWS = 0;

class Solution {
private:
    vector<vector<int>> vecOfVec;
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < MINROWS || numRows > MAXROWS)
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

    void printTwoDVector(vector<vector<int>> twoDVec)
    {
        for(auto& vec:twoDVec)
        {
            for(auto& i: vec)
            {
                cout <<  i << " ";
            }
            cout << endl;
        }
    }

    void printOneDVector(vector<int> oneDVec)
    {
        for(auto& i: oneDVec)
            cout << i << " ";
        cout << endl;
    }

    vector<int> getRow(int rowIndex) {
        vecOfVec.clear();
        int numRows = rowIndex+1;
        if(numRows < MINROWS || numRows > MAXROWS)
            return vecOfVec[0];
        auto twoDVec = generate(numRows);
        printTwoDVector(twoDVec);
        cout << vecOfVec.size() << endl;
        return vecOfVec[rowIndex];
    }
};

int main()
{
    Solution sol;
    int n = 30;
    auto twoDVec = sol.generate(n);
    // sol.printTwoDVector(twoDVec);
    int index = 30;
    sol.printOneDVector(sol.getRow(index));
    return 0;
}