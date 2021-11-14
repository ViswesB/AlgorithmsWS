/*
347. Top K Frequent Elements
Medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

 

Constraints:

    1 <= nums.length <= 105
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
    //use max heap and heapify
private:
    struct node {
        int val;
        int freq;
        node(int x,int y): val(x),freq(y) {} 
    };
    
    struct mycomparator
    {
        bool operator()(node const& lhs,node const& rhs) {
            return lhs.freq < rhs.freq;    
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<node,vector<node>,mycomparator> maxHeap;
        unordered_map<int,int> uoFreq;
        vector<int> ans;
        
        //gather freq of each val
        for(int num:nums) {
            uoFreq[num] += 1;
        }
        
        //heapify
        for(auto itr:uoFreq) {
            maxHeap.push(node(itr.first,itr.second));
        }

        
        //remove top element k times
        while(k > 0) {
            k--;
            auto elemNode = maxHeap.top();
            maxHeap.pop();
            ans.push_back(elemNode.val);
        }
        
        return ans;
    }
};

int main() {
    int k = 2;
    vector<int> nums = {1,1,1,2,2,3};
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto ans = sol->topKFrequent(nums,k);
    for(auto i: ans)
        cout << i << endl;
    return 0;
}