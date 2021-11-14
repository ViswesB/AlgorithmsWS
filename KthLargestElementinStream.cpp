/*
Kth Largest Element in a Stream
Easy

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

 

Constraints:

    1 <= k <= 104
    0 <= nums.length <= 104
    -104 <= nums[i] <= 104
    -104 <= val <= 104
    At most 104 calls will be made to add.
    It is guaranteed that there will be at least k elements in the array when you search for the kth element.

Accepted
163,153
Submissions
313,655
*/

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

class KthLargest {
private:
    int m_K;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
public:
    KthLargest(int k, vector<int>& nums) {
        m_K = k;
        for(int elem:nums) {
            add(elem);
        }
    }
    
    int add(int val) {
        if(minHeap.size() < m_K)
            minHeap.push(val);
        else {
            if(val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// ["KthLargest","add","add","add","add","add"]
// [[1,[-2]],[-3],[0],[2],[-1],[4]]

int main() {
    int k = 1;
    vector<int> nums = {-2};
    unique_ptr<KthLargest> kl = make_unique<KthLargest>(k,nums);
    cout << kl->add(-3) << endl;
    cout << kl->add(0) << endl;
    cout << kl->add(2) << endl;
    cout << kl->add(-1) << endl;
    cout << kl->add(4) << endl;
    return 0;
}

