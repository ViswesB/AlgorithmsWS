/*
Find All numbers disappeared in an array
448. Find All Numbers Disappeared in an Array
Easy

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

 

Constraints:

    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n

 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

*/

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {      
        if(nums.size()==1)
            return {};
        
        vector<int> ans;
        unordered_set<int> uoSet;
        int n = nums.size();
        
        for(int i=0;i<n;i++) {
            uoSet.insert(nums[i]);
        }
                
        for(int i=1;i<=n;i++) {
            auto ret = uoSet.insert(i);
            if(ret.second)
                ans.emplace_back(i);
        }
        
        return ans;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto missingNumbers = sol->findDisappearedNumbers(nums);
    for(auto num: missingNumbers)
        cout << num << "\t";
    cout << endl;
    return 0;
}