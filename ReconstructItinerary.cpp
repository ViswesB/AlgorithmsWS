/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<string,list<string>> uoDest;
    list<string> adjList;
    vector<string> iternary;
    
    void dfs(string from) {
        iternary.push_back(from);
    
        if(uoDest.end() == uoDest.find(from))
            return;
        
        for(auto itr=uoDest[from].begin();itr!=uoDest[from].end();) {
            auto dest = *itr;
            if(uoDest[dest].size() > 0 || uoDest[from].size() <= 1) {
                itr = uoDest[from].erase(itr);
                dfs(dest);
            }
            else
                itr++;
            
             if(uoDest[from].size() == 0)
                itr = uoDest[from].end();
        }
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::string from = "JFK";
        //sort tickets
        sort(tickets.begin(),tickets.end(),[] (vector<string>& lhs,vector<string>& rhs) {
            return lhs[1] > rhs[1];
        });
        
        //prepare source to destination list
        for(int i=0;i<tickets.size();i++) {
            auto itr = uoDest.find(tickets[i][0]);
            if(uoDest.end() != itr) {
                adjList = itr->second;
            }
            
            adjList.push_front(tickets[i][1]);
            uoDest[tickets[i][0]] = adjList;
            adjList.clear();
        }
        
        dfs(from);
        return iternary;
    }
};

int main() {
    vector<vector<string>> tickets = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"}
    };
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto iternary = sol->findItinerary(tickets);
    for(auto location:iternary) 
        cout << location << "\t";
    cout << endl;
    return 0;
}