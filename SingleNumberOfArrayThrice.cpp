/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

 

Constraints:

    1 <= nums.length <= 3 * 104
    -231 <= nums[i] <= 231 - 1
    Each element in nums appears exactly three times except for one element which appears once.

*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /* ((3*(Individual elem sum)) - (sum of all elements)) / 2 */
    int singleNumber(vector<int>& nums) {
        if(nums.size() < 0 || nums.size() > 30000)
            return 0;
        int uNum = 0;
        map<int,int> m;
        int indSum = 0;
        int totSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= INT_MIN || nums[i] >= INT_MAX) {
                cout << "returning as nums[i]" << nums[i] << endl;
                return 0;
            }
            auto ret = m.insert(pair<int,int>(nums[i],i));
            if(ret.second)
                indSum += nums[i];
            totSum += nums[i];
        }
        uNum = ((3*indSum)-totSum)/2;
        return uNum;    
    }
};

int main()
{
    //vector<int> nums = {2,2,3,2};
    //vector<int> nums = {0,1,0,1,0,1,99};
    vector<int> nums = {43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
    Solution sol;
    cout << "Unique Number is:" << sol.singleNumber(nums) << endl;
    return 0;
}