/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/
//#include <iostream>
//#include<bits/stdc++.h> //precision
//#include <iomanip> //precision print
using namespace std;

class Solution {
public:
    int mySqrt(int n) {
        //Newton Algorithm is x_i = (x_i + n/x_i) / 2;
        double xi = (double)n;
        double nxi = 0;
        // double diffPrecision = 0.000000;
        // double precision = 0.000000; //6 digit precision
        while(xi != 0) {
            if(nxi != xi)
                nxi = xi;
            else
                break;
            xi = (xi + (n/xi))/2;
            //cout << setprecision (15) << "xi:" << xi << endl;
        }
        return xi;
    }
};

int main()
{
    int n = 40000;
    Solution sol;
    //cout << sol.mySqrt(n) << endl;
    return 0;
}