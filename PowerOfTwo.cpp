/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false

Example 4:

Input: n = 4
Output: true

Example 5:

Input: n = 5
Output: false

*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwoItr(int n) {
        int x = 2;
        int itr = 1;

        if(n < INT_MIN || n > INT_MAX)
            return false;
        if(n==1)
            return true;
        if(n==2)
            return true;

        while(x < n)
        {
            itr++;
            if(itr == 31)
                return false;
            else 
                x = x * 2;
            if (x == n)
                return true;
        }

        return false;
    }

    bool isPowerOfTwo(int n)
    {
        //base condition
        if (n == 0)
            return false;
        if(n == 1)
            return true;
        
        if (n%2)
            return false;
        return isPowerOfTwo(n >> 1);
    }
};

int main()
{
    Solution sol;
    int n = 1024;
    cout << boolalpha << "Ret is :" << sol.isPowerOfTwo(n) << endl;
    return 0;
}