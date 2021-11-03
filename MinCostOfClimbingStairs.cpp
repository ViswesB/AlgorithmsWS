/*
746. Min Cost Climbing Stairs
Easy

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

 

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        [10,15,20] 
        idea is
        to start solving subproblems of cost to reach top floor
        from end
        here top floor refers to next elem of top of array
        i.e. next of 20
        from 20th pos, to reach top cost is 20 + 0(top floor)
        from 15th pos, to reach top cost will 15 + 20 or 15
        picking min (15 + 20 , 15)
        from 10th pos, to reach top cost will be 
        10 + 15 +20  or 10 + 20 . min is 30
                        -------------
        COST ARRAY      30 | 15 |20                
                        -------------        
        minimum cost if we start at index 0 or index 1 to reach cost is
        min(30,15) = 15.
        */
        
        //add top floor cost as 0
        cost.push_back(0);
        //as we are starting at end, we can make only one jump 
        //to avoid overflow starting at top floor - 3
        int n = cost.size()-3;
        
        for(int i=n;i>=0;i--) {
            //cost at step i will be cost at that step + one step 
            // or cost at that step + 2 step
            cost[i] = cost[i] + min(cost[i+1],cost[i+2]);
        }
        
        return min(cost[0],cost[1]);
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    // vector<int> cost = {10,15,20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << sol->minCostClimbingStairs(cost) << endl;
    return 0;
}