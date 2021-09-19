/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1

 

Constraints:

    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1

*/

//PARTIAL SUCCESS

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missingNum = 1; // Min Postive Number
        int maxSoFar = INT_MIN;
        int nextToMissinNum = INT_MIN;

        if(nums.size() < 1)
           return missingNum;
        
        if(nums.size() == 1) {
           if(nums[0] <= 0)
              return missingNum; 
        }

        for(auto i:nums)
        {
            if(i <= 0) continue;
            if((i == missingNum) && (i > 0))
                missingNum++;
            else if(i > maxSoFar)
                maxSoFar = i;

            if ((i <= maxSoFar) && (i >= missingNum))
                nextToMissinNum = i;
            
            if(missingNum == nextToMissinNum)
                missingNum++;
            cout << "nxt Missing Num:" << nextToMissinNum << endl;
        }
        
        if(missingNum == maxSoFar) {
            return ++missingNum;
        }

        return missingNum;
    }
};

int main()
{
    // vector<int> nums = {7,8,9,1,3};
    // vector<int> nums = {1,2,0};
    // vector<int> nums = {3,4,-1,1};
    // vector<int> nums = {7,8,9,11,12};
    // vector<int> nums = {1,1};
    // vector<int> nums = {2,1};
    // vector<int> nums = {-1,-2,1};
    // vector<int> nums = {0};
    // vector<int> nums = {1,2,6,3,5,4};
    vector<int> nums = {0,2,2,4,0,1,0,1,3};

    Solution sol;
    cout << "Missing Positive Number:" << sol.firstMissingPositive(nums) << endl;
    return 0;
}