/*
541. Reverse String II
Easy

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

 

Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:

Input: s = "abcd", k = 2
Output: "bacd"

 

Constraints:

    1 <= s.length <= 104
    s consists of only lowercase English letters.
    1 <= k <= 104

*/

#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(string& s,int start,int end) {
        while(start < end) {
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            start++;
            end--;
        }
    }
    
    string reverseStr(string s, int k) {
        int n = s.length()-1;
        int start = 0;
        int end = 0;
        
        if(k > n) {
            reverseString(s,start,n);
            return s;
        }
        
        for(int i=0;i<n;i++){
            if(i == start) {
                end = start + k - 1;
                if(end > n)
                    end = n;
                reverseString(s,start,end);
                start = end + k + 1;
            }
        }
        return s;
    }
};

int main() {
    string str = "abcdefg";
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->reverseStr(str,2) << endl;
}