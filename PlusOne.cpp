/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [0]
Output: [1]
Explanation: The array represents the integer 0.
Incrementing by one gives 0 + 1 = 1.
Thus, the result should be [1].

Example 4:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

 

Constraints:

    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.
*/

#include <iostream>
#include <bits/stdc++.h> //pow
#include <vector>
using namespace std;

class Solution {
    public:

    int sumOfArray(vector<int>& nums,int curSize)
    {
        int sum=0;
        for(int i:nums)
        {
            sum += (i * ((int)pow(10,curSize)));
            curSize--;
        }

        sum += 1;
        return sum;
    }

    vector<int> breakIntoArray(int maxSum,int curSize)
    {
        vector<int> breakVec;
        while(curSize >= 0) {
            int div = ((int)pow(10,curSize));
            int elem = (maxSum / div);
            breakVec.push_back(elem);
            maxSum = (maxSum % div);
            curSize--;
        }
        return breakVec;
    }

    vector<int> plusOneTry2(vector<int>& nums)
    {
        vector<int> retVec;
        int lastElem = nums.size()-1;
        int newArraySize = nums.size();
        if(nums[lastElem] == 9) {
            int maxSum = sumOfArray(nums,lastElem);
            if(((int)pow(10,nums.size())) != maxSum)
                newArraySize = nums.size() - 1;
            retVec = breakIntoArray(maxSum,newArraySize);
            return retVec;
        } 
        else {
            nums[lastElem] += 1;
            return nums;
        }
    }

    vector<int> plusOne(vector<int>& nums)
    {
        vector<int> retVec;
        bool isPrevElemNine = false;
        int lastElem = nums.size()-1;
        int newArraySize = nums.size();
        if (nums[lastElem] != 9) {
            nums[lastElem] += 1;
            return nums;
        }
        else
            isPrevElemNine = true;

        for(int i=nums.size()-1;i>=0;i--)
        {
            //If current element is 9 and prev element is 9 as well then 
            if(nums[i] == 9) {
                if(isPrevElemNine) {
                    // replace 9 with 0
                    retVec.insert(retVec.begin(),0);
                    isPrevElemNine = true;
                    //if 1st element is 9 as well then add 1 at front and 0 at end
                    if(i==0) {
                        retVec.insert(retVec.begin(),1);
                    }
                    
                }
                else {
                    retVec.insert(retVec.begin(),nums[i]);
                }
            }
            //else add 1 to present element
            else {
                int val = 0;
                if(isPrevElemNine)
                    val = nums[i] + 1;
                else
                    val = nums[i];
                retVec.insert(retVec.begin(),val);
                isPrevElemNine = false;
            }
        }
        return retVec;
    }
  
    vector<int> plusOneTry1(vector<int>& nums)
    {
        vector<int> retVec;
        int sum = 0;
        cout<< "size of arr:" << nums.size() << " and 0th elem" << nums[0] << endl;
        int curSize = nums.size()-1;
        if(nums.size() == 10) {
            if(nums[0] > 2) {
                return retVec;
            }
            else {
                int maxIntPowValue = (2 * ((int)pow(10,curSize)));
                int arrMaxIntPowValue = (nums[0] * ((int)pow(10,curSize)));
                if(arrMaxIntPowValue > maxIntPowValue) {
                    return retVec;
                }
            }
        }

        if(nums.size() >= 0 && nums.size() <= 100)
        {   
            for(int i:nums)
            {
                sum += (i * ((int)pow(10,curSize)));
                curSize--;
            }

            sum += 1;

            curSize = nums.size() -1;
            for(auto itr = nums.begin(); itr != nums.end() ; itr++)
            {
                if(sum < 0)
                    break;
                cout << "sum is : " << sum << "-- size:"  << curSize << endl;
                int div = ((int)pow(10,curSize));
                int elem = (sum / div);
                sum = (sum % div);
                cout << "element:" << elem << endl;
                if(elem >= 0 && elem <= 9)
                    retVec.push_back(elem);
                else if(elem == 0)
                    retVec.push_back(0);
                // handle edge case of 10
                else if(elem == 10) {
                    retVec.push_back(1);
                    retVec.push_back(0);
                }
                curSize--;
            }
            
            //for(auto itr = retVec.begin(); itr != retVec.end() ; itr++)
            //    cout << "value is " << *itr << endl;
        }
        return retVec;
    }
};

int main()
{
    //vector<int> inpArr = {1,2,3};
    //vector<int> inpArr  = {4,3,2,1};
    //vector<int> inpArr = {1,4,9};
    //vector<int> inpArr = {8,8,9};
    //vector<int> inpArr = {8,9};
    //vector<int> inpArr = {0};
    //vector<int> inpArr = {9};
    //vector<int> inpArr = {9,8,7,6,5,4,3,2,1,0};
    vector<int> inpArr = {2,1,4,7,8,3,6,4,9};
    //vector<int> inpArr = {5,6,2,0,0,4,6,2,4,9};
    
    vector<int> opArr;
    Solution sol;
    opArr = sol.plusOne(inpArr);
    for(int i:opArr)
        cout << "opArr[i]" << i << endl;
    return 0;
}