/*
35. Search Insert Position
Easy

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



Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104


*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int recBinarySearch(vector<int>& nums,int lowerB, int upperB,int target) {
       if(lowerB > upperB)
           return lowerB;
       else if(lowerB == upperB) {
           if(target > nums[lowerB])
              return lowerB+1;
           else
              return lowerB;
       } 
        
       int midB = lowerB + (upperB - lowerB)/2;
       
       if(nums[midB] == target)
           return midB;
       else if(target > nums[midB])
           return recBinarySearch(nums,midB+1,upperB,target);
       else
           return recBinarySearch(nums,lowerB,midB-1,target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if((nums.size()==1) && (nums[0] == target))
            return 0;
        
        return recBinarySearch(nums,0,nums.size()-1,target);
    }
};


int main()
{
    Solution sol;
    vector<int> arr  = {1,3,5,6};
    int target = 5;
    // int target = 6;
    // int target = 1;
    // int target = 0;
    // int target = 7;
    auto indexFound = sol.searchInsert(arr,target);
    cout << "Target found at index: " << indexFound << endl;
}
