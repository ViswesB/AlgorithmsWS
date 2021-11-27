/*
238. Product of Array Except Self
Medium

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 

Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
Accepted
947,513
Submissions
1,507,335
*/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0)
            return {1};
        
        if(nums.size()==1)
            return nums;
        
        int n = nums.size();
        
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> ans(n,0);
        
        //calculate left
        left[0] = 1 * nums[0];
        
        for(int i=1;i<n;i++) {
            left[i] = nums[i] * left[i-1];
        }
        
        
        //calculate right
        right[n-1] = 1 * nums[n-1];
        
        for(int i=n-2;i>=0;i--) {
            right[i] = right[i+1] * nums[i];
        }
        
        ans[0] = 1 * right[1];
        ans[n-1] = 1 * left[n-2];
        //calculate answer
        for(int i=1;i<n-1;i++) {
            ans[i] = left[i-1] * right[i+1];
        }
        
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto ans = sol->productExceptSelf(nums);
    for(auto val : ans)
        cout << val << "\t";
    cout << endl;
    return 0;
}