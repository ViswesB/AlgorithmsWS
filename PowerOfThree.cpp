/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true

Example 2:

Input: n = 0
Output: false

Example 3:

Input: n = 9
Output: true

Example 4:

Input: n = 45
Output: false

 

Constraints:

    -231 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThreeRecursion(int n) {
        if (n==1)
            return true;

        if(n==3)
            return true;

        if(n == 0)
            return false;

        if(n < INT_MIN || n > INT_MAX)
            return false;

        if(n % 3)
            return false;
        else
            return isPowerOfThree(n/3);
    }

    bool isPowerOfThree(int n)
    {
        if (n==1)
            return true;

        if(n==3)
            return true;

        if(n == 0)
            return false;

        if(n < INT_MIN || n > INT_MAX)
            return false;

        int lastDigit = n % 10;


        if(lastDigit == 3 || lastDigit == 9 || lastDigit == 7 || lastDigit == 1)
            return true;
        else 
            return false;
    }
};

int main()
{
    Solution sol;
    int n = 1162261467;
    cout << boolalpha <<  "Ret is: " << sol.isPowerOfThree(n) << endl;
    return 0;
}