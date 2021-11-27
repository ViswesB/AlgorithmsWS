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
        //to keep track of right side/postfix product
        int product = 1;
        vector<int> ans(n,0);
        
        //calculate left
        ans[0] = 1 * nums[0];
        for(int i=1;i<n;i++)
            ans[i] = nums[i] * ans[i-1];
        
        //calculate right
        for(int i=n-1;i>=1;i--) {
            // int temp = nums[i];
            ans[i] = product * ans[i-1];
            product *= nums[i];
        }
        
        ans[0] = 1 * product;
        
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