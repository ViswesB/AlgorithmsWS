/*
986. Interval List Intersections
Medium

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:

Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Example 3:

Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []

Example 4:

Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]

 

Constraints:

    0 <= firstList.length, secondList.length <= 1000
    firstList.length + secondList.length >= 1
    0 <= starti < endi <= 109
    endi < starti+1
    0 <= startj < endj <= 109
    endj < startj+1
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Solution {
    bool isIntersectionPossible(const int& s1,
                                const int& e1,
                                const int& s2,
                                const int& e2
                               ) 
    {
        if((s1 <= e2) && (e1 >= s2))
            return true;
        else
            return false;
    }
    
    vector<int> getIntersection(const int& s1,
                                const int& e1,
                                const int& s2,
                                const int& e2
                               )
    {
        return {max(s1,s2),min(e1,e2)};
    }
    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if((firstList.size() == 0) || (secondList.size() == 0))
            return {};
        
        vector<vector<int>> intersectionList;
        
        //two pointers for each list
        int left = 0;
        int right = 0;
        
        while(left < firstList.size() && right < secondList.size()) {
            //find intersection
            //dont copy but reference
            auto& pointA = firstList[left];
            auto& pointB = secondList[right];
            if(isIntersectionPossible(pointA[0],pointA[1],pointB[0],pointB[1])) {
                intersectionList.emplace_back(
                    getIntersection(pointA[0],pointA[1],pointB[0],pointB[1]));         
            }
            //decide whether firstList to be incremented or secondList
            //it is done based on end point, which is bigger
            if(pointA[1] >= pointB[1])
                right++;
            else if(pointA[1] <= pointB[1])
                left++;
        }
        
        return intersectionList;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    vector<vector<int>> first = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> second = {{1,5},{8,12},{15,24},{25,26}};
    auto intersectionList = sol->intervalIntersection(first,second);
    for(auto interPoint: intersectionList)
        cout << "[" << interPoint[0] << ", " << interPoint[1] << "]" << "\t";
    return 0;
}