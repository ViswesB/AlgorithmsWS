/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1

 

Constraints:

    1 <= nums.length <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104
    Each element in the array appears twice except for one element which appears only once.

*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumberusingXOR(vector<int>& nums) {
         int uniqueNum = 0;
        for(int i=0;i<nums.size();i++)
        {
            uniqueNum ^= nums[i];
        }
        return uniqueNum;        
    }

    /*
    *   Formulae --> ((2* (Sum Of Individual Elements) - (Sum of all elements in array))
    */
    int singleNumber(vector<int>& nums) {
        int uniqueNum = 0;
        map<int,int> m;
        int totalSum = 0;
        int individualSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            auto ret = m.insert(pair<int,int>(nums[i],i));
            if(ret.second)
                individualSum += nums[i];
            totalSum += nums[i];
        }
        uniqueNum = ((2 * (individualSum)) - (totalSum));
        return uniqueNum;        
    }
};



int main()
{
    vector<int> nums = {1,2,4,1,2};
    Solution sol;
    cout << "Unique Number:" << sol.singleNumber(nums) << endl;
}
