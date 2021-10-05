/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

 

Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109

 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater
using namespace std;

class Solution {
public:
    //using sort not recommended
    void mergebad(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //add elements of nums2 to nums1
        int orgSize = nums1.size();
        for(int i=m, j=0;i<orgSize;i++,j++){
            nums1[i] = nums2[j];
        }
        //sort in increasing/ascending order
        sort(nums1.begin(),nums1.end());
    }

    // Idea is to use two indexes and point both to end of two vectors
    // use two pointers from nums1 and nums2 at end
    // check among two values pointed which one is biggger and move to k (m+n-1) 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // size of nums1 final sorted array
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
    
        while(k >= 0 && j >= 0 && i >= 0) {
            //compare value of nums1 to nums2 and find which one is bigger
            if(nums1[i] > nums2[j]) {
                //found biggest in nums1 (target itself) so move not copy
                nums1[k] = nums1[i];
                nums1[i] = 0; //replace that with 0
                k--;
                i--;
            }
            else {
                //found biggest on nums2 vector
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        //there could be left over values from either nums1 or nums2 
        while(k >= 0 && j >=0) {
            //copy value from nums2[j] to nums1[k]
            nums1[k] = nums2[j];
            k--;
            j--;
        }

        while(k >= 0 && i >= 0) {
            //copy values from nums1[i] to nums1[k]
            nums1[k] = nums1[i];
            k--;
            i--;
        }
    }
};

int main()
{
    Solution sol;
    // vector<int> arrM = {1,2,3,0,0,0};
    // int m = 3;
    // vector<int> arrN = {2,5,6};
    // int n = 3;
    // vector<int> arrM = {2,4,8,0,0,0};
    // int m = 3;
    // vector<int> arrN = {1,3,5};
    // int n = 3;
    // vector<int> arrM = {1};
    // int m = 1;
    // vector<int> arrN = {};
    // int n = 0;
    vector<int> arrM = {0};
    int m = 0;
    vector<int> arrN = {1};
    int n = 1;
    sol.merge(arrM,m,arrN,n);
    for(int i:arrM)
        cout << i << endl;
    return 0;
}