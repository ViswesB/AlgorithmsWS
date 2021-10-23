/*
189. Rotate Array
Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

 

Follow up:

    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?


*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) {
            if( k % n == 0)
                return;
        }

        vector<int> rotatedNums(n);
        
        for(int i=0;i<n;i++) {
            if(i+k < n) {
                rotatedNums[i+k] = nums[i];
            }
            else {
                //array out of bounds so move to front of the array
                auto iK = (i+k) % n;
                rotatedNums[iK] = nums[i];
            }
        }
        
        nums = move(rotatedNums);
    }

    void reverse(vector<int>& nums, int start,int end) {
        int temp = INT_MIN;
        while(start < end) {
            temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            start++;
            end--;
        }
    }

    void rotateByReverse(vector<int>& nums,int k) {
        int n = nums.size();
        if(n == 1)
            return;
            
        if(k > n) {
            if( k % n == 0)
                return;
            else k = k % n;
        }

        // idea to do in-place 
        // a. reverse nums vector
        reverse(nums,0,nums.size()-1);
        // b. reverse nums vector upto k in first step
        reverse(nums,0,k-1);
        // c. reverse nums vector from k to end
        reverse(nums,k,nums.size()-1);
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {1,2};
    // int k = 24;
    int k = 2;
    shared_ptr<Solution> sol = make_shared<Solution>();
    // sol->rotate(nums,k);
    // sol->reverse(nums,k,nums.size()-1);
    sol->rotateByReverse(nums,k);
    for(auto i:nums)
        cout << i << "\t";
    cout << endl;
    return 0;
}