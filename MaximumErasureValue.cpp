/*
1695. Maximum Erasure Value
Medium

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        int maxSum = 0;
        unordered_set<int> uniqueSet;
        
        while (end < n) {
            auto itr = uniqueSet.find(nums[end]);
            if(uniqueSet.end() == itr) {
                uniqueSet.insert(nums[end]);
                sum += nums[end];
                end++;
            }
            else {
                uniqueSet.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
            maxSum = max(sum,maxSum);
        }
        
        return maxSum;
    }
};

int main() {
    vector<int> nums = {4,2,4,5,6};
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->maximumUniqueSubarray(nums) << endl;
    return 0;
}