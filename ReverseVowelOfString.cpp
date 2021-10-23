/*
345. Reverse Vowels of a String
Easy

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

 

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"

 

Constraints:

    1 <= s.length <= 3 * 105
    s consist of printable ASCII characters.

*/
#include <bits/stdc++.h>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> uoVowel = {'a','e','i','o','u','A','E','I','O','U'};
        int n = s.length()-1;
        int start = 0;
        int end = n;
        
        while(start < end) {
            auto startIt = uoVowel.find(s[start]);
            auto endIt = uoVowel.find(s[end]);
            
            if((uoVowel.end() != startIt) &&
                (uoVowel.end() != endIt)) {
                //found vowels swap
                char temp = s[end];
                s[end] = s[start];
                s[start] = temp;
                start++;
                end--;
            }          
            else if(uoVowel.end() == startIt)
                start++;
            else if(uoVowel.end() == endIt)
                end--;
        }

        return s;
    }
};

int main() {
    string str = "hello";
    // string str = "Aa";
    shared_ptr<Solution> sol = make_shared<Solution>();
    cout << sol->reverseVowels(str) << endl;
}