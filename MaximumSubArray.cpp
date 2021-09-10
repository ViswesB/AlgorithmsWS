/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

 

Constraints:

    1 <= nums.length <= 3 * 104
    -105 <= nums[i] <= 105
*/

// Divide And Conquer  and Kadane
#include <vector>
#include <iostream>
#include <algorithm> //max
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTotalSum = INT_MIN;
        int maxCurrentSum = 0;
        int maxNegativeSum = INT_MIN; //to consider all negative array
        int i=0;
        if(nums.size() == 1)
            return maxTotalSum = nums[0];

        for(i=0;i<nums.size();i++)
        {
            maxCurrentSum = maxCurrentSum + nums[i];
            if(maxCurrentSum < 0) 
                maxCurrentSum = 0;
            if(maxCurrentSum > maxTotalSum)
                maxTotalSum = maxCurrentSum;
            
            if(nums[i] >= maxNegativeSum) {
                maxNegativeSum = nums[i];
            }
        }

        //Incase if input array is all negative numbers
        if(maxTotalSum == 0)
            maxTotalSum = maxNegativeSum;
        return maxTotalSum;
    }

    int maxSumFromLeftArray(vector<int>& nums,int startIndex, int endIndex,int& maxSumAtIndex)
    {
        int tempSum = 0;
        int maxSum = nums[endIndex];
        cout << "startIndex:" << startIndex << endl;
        cout << "endIndex:" << endIndex <<endl;
        if(startIndex == endIndex)
            return maxSum = nums[startIndex];
        
        for(int i=endIndex; i>=startIndex; i--)
        {
            //if(nums[i] > maxSum)
            //    maxSum = nums[i];
            tempSum += nums[i];
            if (tempSum >= maxSum) {
                maxSum = tempSum;
                maxSumAtIndex = i;
            }
        }
        return maxSum;
    }

    int maxSumFromRightArray(vector<int>& nums,int startIndex, int endIndex,int& maxSumAtIndex)
    {
        int tempSum = 0;
        int maxSum = nums[startIndex];
        if(startIndex == endIndex) {
            maxSumAtIndex = endIndex;
            return maxSum = nums[startIndex];
        }
        
        for(int i=startIndex; i<=endIndex; i++)
        {
            if(nums[i] > maxSum)
                maxSum = nums[i];
            tempSum += nums[i];                
            if (tempSum >= maxSum) {
                maxSum = tempSum;
            }
            maxSumAtIndex = i;
        }
        return maxSum;
    }

    int maxSumFromArray(vector<int>& nums,int startIndex, int endIndex,int& maxSumAtIndex)
    {
        return maxSumFromRightArray(nums,startIndex,endIndex,maxSumAtIndex);
    }

    int maxSubArrayDivideAndConquer(vector<int>& nums)
    {
        int firstElem = 0;
        int lastElem = nums.size()-1;
        int midPivot = 0;    
        int maxLeftSumAtIndex = 0, maxRightSumAtIndex = 0;
        int iMaxLeftSubArraySum = 0, iMaxRightSubArraySum = 0, iMaxCrossSubArraySum = 0;
        
        if(lastElem == 0)
            return nums[lastElem];
        else if(lastElem == 1)
            midPivot = 0;
        else
            midPivot = (lastElem)/2;
        
        
        iMaxLeftSubArraySum = maxSumFromLeftArray(nums,firstElem,midPivot,maxLeftSumAtIndex);

        iMaxRightSubArraySum = maxSumFromRightArray(nums,midPivot+1,lastElem,maxRightSumAtIndex);


        //Find left Index at which max Left Sum was found 
        //Find right Index at which max Right Sum was found.
        //find max sub array for that index
        int tempIndex = 0;
        iMaxCrossSubArraySum = maxSumFromArray(nums,maxLeftSumAtIndex,maxRightSumAtIndex,tempIndex);

        //Find Max among Left/Right/Across Array
        return max((max(iMaxLeftSubArraySum,iMaxRightSubArraySum)),iMaxCrossSubArraySum);
    }
};

int main()
{
    Solution sol;
    //vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    //vector<int> arr = {-2,-1};
    //vector<int> arr = {5,4,-1,7,8};
    //vector<int> arr = {8,-19,5,-4,20};
    //vector<int> arr = {-1,-2,-3,0};
    //vector<int> arr = {5};
    vector<int> arr = {1,2};
    auto maxSum = sol.maxSubArray(arr);
    cout << "max Sum is : " << maxSum << endl;
    return 0;
}