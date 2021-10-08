/*
Maximum Sub Array using Divide and Conquer
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> vecNums;
public:
    int maxSumonLeftArray(int startIndex,int endIndex,int& leftArrayMaxSumAtIndex)
    {
        cout << "startIndex:" << startIndex << endl;
        cout << "endIndex:" << endIndex <<endl;
        if(startIndex == endIndex) {
            leftArrayMaxSumAtIndex = startIndex;
            return vecNums[startIndex];
        }

        auto max_so_far = INT_MIN;
        auto max_ending_here = 0;

        for(int i=endIndex; i>= startIndex; i--) {
            cout << i << endl;
            max_ending_here += vecNums[i];
            if(max_so_far <= max_ending_here) {
                max_so_far = max_ending_here;
                leftArrayMaxSumAtIndex = i;
            }
            
        }
        return max_so_far;
    }

    int maxSumonRightArray(int startIndex,int endIndex,int& rightArrayMaxSumAtIndex) {
        if(startIndex == endIndex) {
            rightArrayMaxSumAtIndex = startIndex;
            return vecNums[startIndex];
        }

        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for(int i=startIndex;i<=endIndex;i++) {
            max_ending_here += vecNums[i];
            if(max_so_far <= max_ending_here) {
                max_so_far = max_ending_here;
                rightArrayMaxSumAtIndex = i;
            }
        }
        return max_so_far;
    }
    //Solving this using divide and conquer
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;

        if(nums.size() == 1)
            return nums[0];

        //Divide the array into left and right using pivot
        int midpivot = nums.size()/2;
        int startIndex = 0;
        int endIndex = nums.size()-1;

        if(endIndex == 1)
            midpivot = 0;


        int leftArrayMaxSumIndex = 0;
        int rightArrayMaxSumIndex = 0;

        vecNums = nums;

        //Find Max Subarray and index at which it is found on left array 
        auto maxSumOnLeft = maxSumonLeftArray(startIndex,midpivot,leftArrayMaxSumIndex);
        //Find Max Subarray and index at which it is found on right array
        auto maxSumOnRight = maxSumonRightArray(midpivot+1,endIndex,rightArrayMaxSumIndex);
        int indexFound = INT_MIN;
        //Find max subarray between index on left and right array
        auto maxSumInBetween = maxSumonRightArray(leftArrayMaxSumIndex,rightArrayMaxSumIndex,indexFound);
        //Max among left / right / in-between
        cout << "left: " << maxSumOnLeft << " found at index: " << leftArrayMaxSumIndex << endl;
        cout << " right: " << maxSumOnRight << " found at index: " << leftArrayMaxSumIndex << endl;
        cout << " middle: " << maxSumInBetween << endl;
        return max(maxSumInBetween,max(maxSumOnLeft,maxSumOnRight));
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {-1,-1,-2,-2};
    cout << "max sub array : " << sol.maxSubArray(nums);
}