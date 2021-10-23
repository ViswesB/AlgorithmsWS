/*
557. Reverse Words in a String III
Easy

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

 

Constraints:

    1 <= s.length <= 5 * 104
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
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
    
    string reverseWords(string s) {
        int n = s.length()-1;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++) {
            //look for whitespace
            if(s[i] == ' ') {
                end = i-1;   
                reverseString(s,start,end);
                if(i+1 <= n) {
                    start = i+1;
                    end = 0;
                }
            }
        }
        
        //reverse last word
        reverseString(s,start,n);
        return s;
    }
};

int main() {
    string str = "Welcome to My World";
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->reverseWords(str) << endl;
    return 0;
}