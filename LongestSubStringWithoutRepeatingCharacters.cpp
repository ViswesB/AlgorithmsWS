/*
3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        
        int start = 0;
        int end = 0;
        int maxLen = 0;
        set<char> uoChar;
        
        while(end < s.length()) {
            auto itr = uoChar.find(s[end]);
            if(uoChar.end() == itr) {
                uoChar.insert(s[end]);
                end++;
                maxLen = max(int(uoChar.size()),maxLen);
            }
            else {
                uoChar.erase(s[start]);
                start++;
            }
        }
        
        return maxLen;
    }
};

int main() {
    string str = "pwwkew";
    // string str = "dvdy";
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->lengthOfLongestSubstring(str) << endl;
    return 0;
}