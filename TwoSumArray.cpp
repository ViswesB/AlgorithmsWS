/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> uomap;
        for(int i=0;i<nums.size();i++) {
            auto it = uomap.find(target-nums[i]);
            if(it != uomap.end()) {
                //found value at indices
                return {i , it->second};
            }
            uomap.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2,11,7,15};
    int target = 9;
    Solution sol;
    auto indices = sol.twoSum(nums,target);
    for(auto i:indices)
        cout << i << "\t";
    cout << endl;
}