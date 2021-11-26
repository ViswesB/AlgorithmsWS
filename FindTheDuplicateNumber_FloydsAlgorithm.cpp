/*
287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Example 3:

Input: nums = [1,1]
Output: 1

Example 4:

Input: nums = [1,1,2]
Output: 1

 

Constraints:

    1 <= n <= 105
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.

 

Follow up:

    How can we prove that at least one duplicate number must exist in nums?
    Can you solve the problem in linear runtime complexity?


*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 2) {
            if(nums[0] == nums[1])
                return nums[0];
        }
        
        int slow = 0;
        int fast = 0;
        
        //floyds algo will give us indication 
        //whether there is a cycle or not
        while(fast < nums.size()) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) {
                break;
            }
        }
        
        //to find element that is causing cycle
        //we will reset slow to start 
        //keep fast the same
        //move slow and fast by one pointer
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
                break;
        }
        
        return slow;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->findDuplicate(nums) << endl;
    return 0;
}