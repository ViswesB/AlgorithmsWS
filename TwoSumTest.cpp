/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSumConsecutive(vector<int>& nums, int target) {
        vector<int> vecRetSum;
        for(int i=0; i<nums.size();i++) {
            if(i+1 >= nums.size()) {
              cout<< "size of input nums is: " << nums.size() << endl;
              cout << "reached end of vector not found sum target" << endl;
              break;
            }
            if(nums[i] > target)
                continue;
            else {
                if((nums[i] + nums[i+1]) == target) {
                    vecRetSum.push_back(i);
                    vecRetSum.push_back(i+1);
                    break;
                }
            }
        }
        return vecRetSum;
    }

/* This is O(n2) */
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> vecRet;
        vecRet.clear();
        int x, y, p , q = 0;
     
        for(int i=0;i<nums.size();i++)
        {
            int intItr = i;
            if(nums[i] >= target)
                continue;
            else {
                x = nums[i];
                vecRet.push_back(i);
                y = target - nums[i];
                while(intItr+1 != nums.size()) {
                    if(nums[intItr+1] == y) {
                        vecRet.push_back(intItr+1);
                        break;
                    }
                    intItr++;
                }
                if(vecRet.size() != 2) {
                    vecRet.clear();
                }
                else
                    break;
            }
        }
        
        return vecRet;
    }

   /* Using Maps and not sorting */
   //While inserting into map , parellely we are performing find.
   vector<int> twoSumWithMap(vector<int>& nums, int target)
   {
       std::unordered_map<int,int> unOrMap;
       for(int i=0; i< nums.size();  i++)
       {
           std::unordered_map<int,int>::const_iterator itr = unOrMap.find(target - nums[i]);
           if (itr != unOrMap.end())
               return vector<int> {itr->second, i};
            unOrMap[nums[i]] = i;
       }
   }
};

int main()
{
    int maxArraySize = 0;
    int target = 0;
    int input;
    Solution sol;
    vector<int> vecInput;
    vector<int> vecSumIndices;
    std::cout << "Please Enter Max Number of array" << endl;
    std::cin >> maxArraySize;
    std::cout << "Please Enter Target" << endl;
    std::cin >> target;


    for(int i=0;i<maxArraySize;i++) {
        cout << "Please Enter data into arrays at index:" << i << endl;
        cin >> input;
        if(input > 9999)
            input = 0;
        vecInput.push_back(input);
    }

    vecSumIndices = sol.twoSumWithMap(vecInput,target);
    if(!vecSumIndices.empty())
        cout<< "Sum of :" << target << " Is achieved by indices present at: " << vecSumIndices[0] << " and " << vecSumIndices[1] << endl;
    else
        cout << "Target not found in vector" << endl;
    return 0;
}