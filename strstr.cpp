/*
strstr

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size() == 0)
            return -1;
        for(int i=0;i<haystack.size();i++) {
            //compare substring from i to length of needle
            cout << haystack.substr(i,needle.size()) << endl;
            if(haystack.substr(i,needle.size()) == needle)
                return i;
        }
        
        return -1;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    string haystack = "ll";
    string needle = "hello";
    cout << sol->strStr(haystack,needle) << endl;
    return 0;
}

