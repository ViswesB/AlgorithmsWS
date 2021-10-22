/*
283. Move Zeroes
Easy

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            if(nums.size() == 1)
                return;
            
            int n = nums.size();
            int left = 0;
            int right = 0;
            
            for(int i=0;i<n;i++) {
                right = i;
                if(nums[i] != 0) {
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    left++;
                }
            }
        }
        
    void moveZeroesWith2Pointer(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        int n = nums.size();
        //idea is to use two pointers start and next
        // where start is zero is found and not end
        // next is start + 1 , if not 0 
        // swap with start and next
        int startZeroElem = 0;
        int nextElem = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                if(i == n-1)
                    break;
                
                startZeroElem = i;
                nextElem = startZeroElem + 1;
                
                if(nums[nextElem] == 0 && nextElem == n-1)
                    continue;
                
                while(nums[nextElem] == 0) {
                    if(nextElem == n-1)
                        break;
                    else
                        nextElem++;
                }
                //swap
                int temp = nums[nextElem];
                nums[nextElem] = nums[startZeroElem];
                nums[startZeroElem] = temp;  
            }                   
        }
    }
};

int main() {
    vector<int> nums = {0,0,12,0,5};
    shared_ptr<Solution> sol = make_shared<Solution>();
    sol->moveZeroes(nums);
    for(auto i: nums)
        cout << i << endl;
    return 0;
}