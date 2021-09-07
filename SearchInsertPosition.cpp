/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0

Example 5:

Input: nums = [1], target = 0
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int found = -1;
        //Verify if target is less than 1st element 
        if (target <= nums[0]) {
            found = 0;
            return found;
        }
        //Verify if target is greater than last element
        else if (target > nums[nums.size()-1]) {
            found = nums.size();
            return found;
        }

        for (int i=0; i<nums.size();i++)
        {
            if(target > nums[i]){
                if(nums[i+1] >= target) {
                    found = i+1;
                }
            }
            else if (nums[i] == target) {
                found = i;
            }
        }
        return found;
    }
};

int main()
{
    Solution sol;
    vector<int> arr  = {1,3,5,6};
    int target = 7;
    auto indexFound = sol.searchInsert(arr,target);
    cout << "Target found at index: " << indexFound << endl;
}
