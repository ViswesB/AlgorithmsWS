/*
1136. Parallel Courses
Medium

559

15

Add to List

Share
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei.

In one semester, you can take any number of courses as long as you have taken all the prerequisites in the previous semester for the courses you are taking.

Return the minimum number of semesters needed to take all courses. If there is no way to take all the courses, return -1.

 

Example 1:


Input: n = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: The figure above represents the given graph.
In the first semester, you can take courses 1 and 2.
In the second semester, you can take course 3.
Example 2:


Input: n = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: No course can be studied because they are prerequisites of each other.
 

Constraints:

1 <= n <= 5000
1 <= relations.length <= 5000
relations[i].length == 2
1 <= prevCoursei, nextCoursei <= n
prevCoursei != nextCoursei
All the pairs [prevCoursei, nextCoursei] are unique.
Accepted
28,387
Submissions
47,190
*/

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <memory>
using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        //create graph
        vector<list<int>> graph(n+1);
        
        //keep track of visited nodes
        int visitedNodes = 0;
        
        //number of semesters
        int noSem = 0;
        
        //queue - kahns algorithm
        queue<int> qOrder;
        
        //indegree vector
        vector<int> inDegree(n+1,0);
        
        //graph is updated
        for(auto relation: relations) {
            inDegree[relation[1]]++;
            graph[relation[0]].push_front(relation[1]);
        }
        
        //look for courses with in-degree 0
        for(int i=1;i<inDegree.size();i++) {
            if(inDegree[i]==0) {
                qOrder.push(i);
            }
        }
        
        int len = 0;
    
        while(!qOrder.empty()) {
            len = qOrder.size();
            while(len--) {
                auto tempCourse = qOrder.front();
                qOrder.pop();
                for(auto next: graph[tempCourse]) {
                    if(inDegree[next] > 0)
                        inDegree[next]--;
                    if(inDegree[next] == 0)
                        qOrder.push(next);
                }
                visitedNodes++;
            }
            noSem++;
        }
        
        return (visitedNodes!=n) ? -1: noSem;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> relations ={{1,3},{2,3}};
    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->minimumSemesters(n,relations);
    return 0;
}