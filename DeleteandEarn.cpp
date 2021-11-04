/*
740. Delete and Earn
Medium

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

 

Constraints:

    1 <= nums.length <= 2 * 104
    1 <= nums[i] <= 104

Accepted
90,322
Submissions
168,263
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //idea is to prepare dp freq array 
        //then use exclude and include theory
        //where if one number included then leftover/excluded 
        //value will be added to included 
        // i.e. included = nums[i] + previous included value
        // where excluded is if we choose to exclude that value 
        // then choose maximum amongst previous included / excluded
        // example  : {3,2,3,7,4}
        // convert this to freq map till 7 as this is max number in array
            //    ---------------------------------
            //    | 0 | 0 | 1 | 2 | 1 | 0 | 0 | 1 |     <-- freq of numbers
            //    ---------------------------------
            //    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |     <-- index
            // excluded = max(excluded,included)
            // included = (count * nums[i])+ previncluded)
            // answer = max of (excluded,included)
            // excluded : | 0 | 0 | 0 | 2 | 6 | 6 | 6 | 6  |
            // included : | 0 | 0 | 2 | 6 | 6 | 6 | 6 | 13 |
        
        vector<int> dpVec;
        dpVec.resize(10001); //10(4) + 1
        for(int i=0;i<nums.size();i++)
            dpVec[nums[i]]++;
        
        int exclude = 0;
        int include = 0;
        for(int i=0;i<dpVec.size();i++) {
            int prevExclude = exclude;
            exclude = max(include,exclude);
            include = (dpVec[i] * i) + prevExclude;
            prevExclude = exclude;
        }
        
        return max(include,exclude);
    }
};

int main() {
    // vector<int> nums = {2,2,3,3,3,4};
    vector<int> nums = {3,2,3,7,4};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->deleteAndEarn(nums) << endl;
    return 0;
}