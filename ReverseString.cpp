/*
Reverse a string

Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

 

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <iostream>
#include <vector>
#include <algorithm> //swap
using namespace std;

class Solution {
public:
    void reverseStringRecursion(vector<char>& s) {   
        int low = 0;
        int high = s.size() -1;
        swapChar(s,low,high);
    }

    void swapChar(vector<char>& s,int low,int high)
    {
        //Base condition to break
        if(low > high)
            return;

        swap(s[low],s[high]);
        swapChar(s,++low,--high);
    }

    void reverseString(vector<char>& s) {   
        int low = 0;
        int high = s.size() -1;
        while ( low < high)
        {
            char ch = s[low];
            s[low] = s[high];
            s[high] = ch;
            low++;
            high--;
        }
    }
};

int main()
{
    vector<char> s = {'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(s);
    for(auto c:s)
        cout << c << endl;
    return 0;
}

