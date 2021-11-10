/*
The Earliest Moment When Everyone Become Friends
There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

 

Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation: 
The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friends anything happens.
The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.
Example 2:

Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
 

Constraints:

2 <= n <= 100
1 <= logs.length <= 104
logs[i].length == 3
0 <= timestampi <= 109
0 <= xi, yi <= n - 1
xi != yi
All the values timestampi are unique.
All the pairs (xi, yi) occur at most one time in the input.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> rank;
public:
    void constructvector(int n) {
        root.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x) {
        while(x != root[x]){
            x = root[x];
            //path compression
            root[x] = root[root[x]];
        }
        return root[x];
    }
    
    int unionset(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        //already connected
        if(rootX == rootY)
            return 0;
        
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        else {
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
        
        //connected x and y to one component
        return 1;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        constructvector(n);
        //sort logs vector based on timestamp
        sort(logs.begin(),logs.end(),
             [](const vector<int>& lhs,const vector<int>& rhs){
                 return lhs[0] < rhs[0];
                });
        
        //union
        for(auto itr:logs) {
            n -= unionset(itr[1],itr[2]);
            // all components are connected
            // return timestamp
            if(n == 1)
                return itr[0];
        }
        
        return -1;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> logs = {
                {20190101,0,1},
                {20190104,3,4},
                {20190107,2,3},
                {20190211,1,5},
                {20190224,2,4},
                {20190301,0,3},
                {20190312,1,2},
                {20190322,4,5}
                };
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << "earliest timestamp at which all nodes are friends: " << sol->earliestAcq(logs,n) << endl;

    return 0;
}