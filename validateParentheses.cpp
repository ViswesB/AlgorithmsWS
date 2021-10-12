/*
20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

Accepted
1,695,572
Submissions
4,192,247
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> cStack;
        //Built hashmap for quick check
        unordered_map<char,char> uoChar;
        uoChar.insert(pair<char,char>(')','('));
        uoChar.insert(pair<char,char>('}','{'));
        uoChar.insert(pair<char,char>(']','['));
        
            
        for(auto ch:s) {
            //check if character is matching to top of stack
            if(uoChar.end() != uoChar.find(ch)) {
                if(!cStack.empty())  {
                    if(cStack.top() != uoChar.find(ch)->second)
                        return false;
                //Found matching parentheses in stack
                    else
                        cStack.pop();
                }
            }
            else
                cStack.push(ch);
        }
        
        //didnt find matching element and stack is not empty
        if(!cStack.empty())
            return false;
        
        return true;
    }
};

int main() {
    string s;
    Solution sol;
    // s = "{()}";
    s = "}(";
    cout << boolalpha << sol.isValid(s) << endl;
    return 0;
}