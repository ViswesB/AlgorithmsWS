/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

    Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

 

Constraints:

    The input must be a binary string of length 32.

 
Follow up: If this function is called many times, how would you optimize it?
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateOnes(uint32_t n,int counter)
    {
        uint32_t mask = 1;
        if(n == 0)
            return counter;
        uint32_t res = n & mask;
        if(n & mask)
            counter++;
        return calculateOnes(n>>1,counter);
    }

    int hammingWeight(uint32_t n) {
        cout << "n is :" << n << endl;
        int counter = 0;
        return calculateOnes(n,counter);
    }
};

int main()
{
    // uint32_t uI = 00000000000000000000000000001011;
    // uint32_t uI = 00000000000000000000000000000000;
    uint32_t uI = 4294967293;
    Solution sol;
    auto iI = sol.hammingWeight(uI);
    cout << "Number of One's are : " << iI << endl;
    return 0;
}