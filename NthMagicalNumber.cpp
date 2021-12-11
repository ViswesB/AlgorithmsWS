/*
878. Nth Magical Number
Hard

A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2

Example 2:

Input: n = 4, a = 2, b = 3
Output: 6

Example 3:

Input: n = 5, a = 2, b = 4
Output: 10

Example 4:

Input: n = 3, a = 6, b = 4
Output: 8

 

Constraints:

    1 <= n <= 109
    2 <= a, b <= 4 * 104


*/

#include <iostream>
#include <memory>
using namespace std;

class Solution {
    int calculateGCD(int a, int b) {
        int remainder = a % b;
        
        if(remainder == 0)
            return b;
        
        return calculateGCD(b, remainder);
    }
    
public:
    //formulae 's used here
    // to find upper limit to find nth magical number it is 
    // upper = n * min(a,b)
    // formulae to find unique magical number is 
    // x / a + x /b + x /(lcm(a,b))
    // what is lcm(a,b) ??
    // a  * b = lcm(a,b) * gcd(a,b)
    // so lcm(a,b) =  a * b / gcd(a,b)
    
    // what is gcd(a,b) == , using euclidean algorithm

    // 64 ÷ 40 = 1 with a remainder of 24
    // 40 ÷ 24 = 1 with a remainder of 16
    // 24 ÷ 16 = 1 with a remainder of 8
    // 16 ÷ 8 = 2 with a remainder of 0.
    //gcd is 8 
    
    int nthMagicalNumber(int n, int a, int b) {
        if(a == 0 || b == 0)
            return 0;
        
        long low = 1;
        long high =  (long)n * min(a,b);
        long mid = 0;
        long gcd = calculateGCD(a,b);
        long lcm = (a * b) / gcd;
        long mod = 1000000007;
        
        //use binary search
        while(low < high) {
            mid = low + (high-low)/2;
            long val = (mid/a) + (mid/b) - (mid/lcm);
            
            //if value is less than n, then value didnt reach required 
            //magical number. so increase low
            if(val < n)
                low = mid+1;
            else
                high = mid;
        }
        
        return (long)low % mod;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    // n = 4, a = 2, b = 3
    cout << sol->nthMagicalNumber(4,2,3) << endl;
    return 0;
}