/*
1217. Minimum Cost to Move Chips to The Same Position
Easy

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

    position[i] + 2 or position[i] - 2 with cost = 0.
    position[i] + 1 or position[i] - 1 with cost = 1.

Return the minimum cost needed to move all the chips to the same position.

 

Example 1:

Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.

Example 2:

Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.

Example 3:

Input: position = [1,1000000000]
Output: 1

 

Constraints:

    1 <= position.length <= 100
    1 <= position[i] <= 10^9
*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//Explanation
/*
consider we have chips [2 2 2 3 3] where 1st chip is at pos 2 and 2nd at pos 2 so on
now consider this in format parity [odd even odd even odd].
algorithm is that 
cost involved to move all odd chips to 1st odd position is 0
now, cost involved to move all even chips to 1st even position is also 0
at this step we transformed array [0 3 2] == i.e. 3 chips at even pos and 2 chips at odd
to [2 3] where 2 chips at first odd and 3 chips at 1st even
Now, question is to decide what will be min cost , either to transfer all chips from even to odd 
or odd to even
even to odd will cost 3 , where odd to even cost 2 . so min(3,2)
*/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        //loop through array to count freq of all odd and even positioned chips
        for(int pos: position) {
            if(pos%2) even++;
            else odd++;
        }
        //now we have frequency of even and odd.
        //hypothetically assume them at 1st even and 1st odd
        //decide what will be min cost among these movements
        return min(even,odd);
    }
};

int main() {
    vector<int> position = {2,2,2,3,3};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->minCostToMoveChips(position) << endl;
    return 0;
}