/*
Hamming Distance
461. Hamming Distance
Easy

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:

Input: x = 3, y = 1
Output: 1

 

Constraints:

    0 <= x, y <= 231 - 1
*/

#include <iostream>
#include <memory>
using namespace std;

class Solution {
private:
    int count=0;
public:
    int hammingDistance(int x, int y) {
        if(x==0 && y==0)
            return count;
        
        //grab last bit using mask
        int mask = 1;

        //apply xor/or if different increment count
        if((x & 1) ^ (y & 1))
            count++;

        //move to next bit till values are 0 for x & y
        return hammingDistance(x>>1,y>>1);
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->hammingDistance(1,4);
    return 0;
}