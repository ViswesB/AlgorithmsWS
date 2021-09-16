/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    -100.0 < x < 100.0
    -2p31 <= n <= 2p31-1
    -10p4 <= xn <= 10p4

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return x;
        if(n >= INT_MAX)
            return 1;
        if(n <= INT_MIN)
            return 1;
        int i = 1;
        double dPow = x;
        while (i != abs(n))
        {
            dPow = dPow * x;
           //cout << "dPow:" << dPow << " i:" << i << endl; 
            i++;
        }
        
        if (n < 0){
            dPow = 1/dPow;
        }

        return dPow;
    }
};

int main()
{
    Solution sol;
    double d = 1.00000;
    int n = 2147483647;
    cout << setprecision(17) << sol.myPow(d,n);
    return 0;
}