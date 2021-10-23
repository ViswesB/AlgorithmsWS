/*
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

class Solution {
public:      
    string frequencySort(string s) {
        int n = s.length();
        map<char,int> freqMap;
        for(int i=0;i<s.length();i++) {
            freqMap[s[i]]++;
        }
        
        vector<pair<char,int>> vecPair;
        for(auto itr=freqMap.begin();itr!=freqMap.end();itr++) {
            vecPair.push_back(make_pair(itr->first,itr->second));
        }
        
        sort(vecPair.begin(),vecPair.end(),
            [] (const pair<char,int>& v1, const pair<char,int>& v2) {
                return v1.second > v2.second;
            }
        );
        
        string resStr;

        for(auto itr=vecPair.begin();itr!=vecPair.end();itr++) {
            for(int i=0;i<itr->second;i++) {
                resStr += itr->first;
            }
        }
        
        return resStr;
    }
};

int main() {
    // string s = "tree";
    // string s = "cccaaa";
    string s = "Aabb";
    shared_ptr<Solution> sol = make_shared<Solution>();
    auto retS = sol->frequencySort(s);
    cout << retS << endl;
    return 0;
}