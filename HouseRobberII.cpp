/*
213. House Robber II
Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int HouseRobberI(vector<int> &nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int cost = max(nums[0],nums[1]);
        int rob1 = nums[0];
        int rob2 = cost;
        
        for(int i=2;i<nums.size();i++) {
            cost = max(cost,nums[i]+rob1);
            rob1 = rob2;
            rob2 = cost;
        }
        return cost;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        //idea is to find max cost from vector except last house
        //and max cost from vector except first house
        vector<int> vec(nums.begin()+1,nums.end());
        // cost from 1st Array
        int cost1 = HouseRobberI(vec);
        vec.clear();
        // cost from 2nd array
        nums.erase(nums.begin()+(nums.size()-1));
        return max(cost1,HouseRobberI(nums));
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    // vector<int> nums = {2,7,9,3,1};
    vector<int> nums = {1,2,3};
    cout << sol->rob(nums) << endl;
    return 0;
}