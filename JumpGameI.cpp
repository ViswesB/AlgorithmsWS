/*
55. Jump Game
Medium

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return true;
        
        // greedy solution
        // moving goal post 
        // if last elem - 1 can reach goal then change goal to last elem -1;
        // at the end if first element == goal then first element reached goal
        // return true;
        // else false
        int goal = size-1;

        for(int i=size-2;i>=0;i--) {
            if(nums[i]+i >= goal)
                goal = i;
        }
        
        return (goal == 0)?true:false;
    }
};

int main() {
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << boolalpha << sol->canJump(nums) << endl;
    return 0;
}