/*
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(!s.length())
            return -1;
        else if(s.length() == 1)
            return 0;
        
        unordered_map<char,int> mymap;
        for(int i = 0;i<s.size();i++)
            mymap[s[i]]++;

        for(auto itr=mymap.begin();itr!=mymap.end();itr++)
            cout << itr->first << "\t" << itr->second << endl;

        for(auto i=0;i<s.size();i++) {
            if(mymap[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};

int main()
{
    string str = "ada";
    Solution sol;
    auto i = sol.firstUniqChar(str);
    cout << "First Unique character found at: " << i  << endl;
    return 0;
}