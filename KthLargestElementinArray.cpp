/*
215. Kth Largest Element in an Array
Medium

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 

Constraints:

    1 <= k <= nums.length <= 104
    -104 <= nums[i] <= 104

Accepted
1,086,400
Submissions
1,766,280
*/

#include <iostream>
#include <memory>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    // Kth Largest with min_heap of size k
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) {
            if(minHeap.size() == k) {
                //queue should only contain maximum value elements
                //compare current element to top and decide to delete or skip
                if(nums[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
            else
                minHeap.push(nums[i]);
        }
        
        return minHeap.top();
    }
};

int main() {
    int k = 2;
    vector<int> nums = {3,2,1,5,6,4};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->findKthLargest(nums,k) << endl;
    return 0;
}