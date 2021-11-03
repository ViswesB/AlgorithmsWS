/*
70. Climbing Stairs
Easy

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
        for n = 5 , solve in reverse 
        at step 5, we can reach in only one way i.e. 1
        at step 4, we can reach 5 in one step
        at step 3, we can reach 5 in 2 ways i.e 1+1/ 2
        which is sum of step 4 and step 5
        same way at step 2 , number of ways = way 3 + way 4
        step 1 , number of ways to reach 5 = way 2 + way 3
        step 0 , starting position to reach 5 = way 1 + way2
        
        to reach step 0 from n, loop should be n-1
        
        no of times required to compute answer from 5th and 4th is 
        4 which n - 1
        ----------------------------
        |  8  | 5 | 3 | 2  | 1 | 1 |                                
        ----------------------------
        */
        
        int one = 1;
        int two = 1;
        
        for(int i=0;i<n-1;i++) {
            //add one and two and swap old one to two.
            int temp = one;
            one = one + two;
            two = temp;
        }
        
        return one;
    }
};

int main() {
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->climbStairs(45) << endl;
    return 0;
}