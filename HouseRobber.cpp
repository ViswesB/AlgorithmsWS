/*
198. House Robber
Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400

Accepted
865,936
Submissions
1,924,455
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        //idea is to compute max cost and keep remembering max cost 
        //compute max cost among first and second house
        int cost = max(nums[0],nums[1]);
        //remember prev cost ideally starts at first house
        int prevCost = nums[0];
        
        //considering that first 2 house are done. starting index at 3rd house
        for(int i=2;i<nums.size();i++) {
            //remember prevcost in temp
            int temp = cost;
            //max cost so far and cost say from 1st house to 3rd house 
            cost = max(cost, prevCost + nums[i]);
            //swap temp to prevCost
            prevCost = temp;
        }
        
        return cost;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    // vector<int> nums = {2,7,9,3,1};
    vector<int> nums = {2,1,1,2};
    cout << sol->rob(nums) << endl;
    return 0;
}