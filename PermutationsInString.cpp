/*
567. Permutation in String
Medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

 

Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.

Accepted
251,629
Submissions
567,887
*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        //idea is to use 2 vectors of a - z 26 characters
        //compare based on sliding window of s1.size()
        vector<int> s1Hash(26,0);
        vector<int> s2Hash(26,0);
        
        int s1Len = s1.size();
        int s2Len = s2.size();
        
        //prepare s1 and s2 has
        for(int i=0;i<s1Len;i++) {
            s1Hash[s1[i]-'a']++;
            s2Hash[s2[i]-'a']++;
        }
        
        //start sliding window on s2
        int left = 0;
        int right = s1Len-1;
        while(right < s2Len) {
            //verify if s1Hash same as s2Has
            if(s1Hash == s2Hash)
                return true;
            //increment right only not crossing s2Len
            if(right+1 < s2Len)
                s2Hash[s2[right+1]-'a']++;
            right++;
            //remove element pointed by left and increment
            s2Hash[s2[left]-'a']--;
            left++;
        }
        
        return false;
    }
};

int main() {
    string s1 = "abc";
    string s2 = "dcbaeo";
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << boolalpha << sol->checkInclusion(s1,s2) << endl;
    return 0;
}