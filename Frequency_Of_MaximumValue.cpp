/*
Given an array ‘nums’ of length N containing positive integers and an array ‘query’ of length ‘Q’ containing indexes, print/store for each query the count of maximum value in the sub-array starting at index ‘i’ and ending at index ‘N-1’.

For eg:- nums = [ 5, 4, 5, 3, 2 ] and query = [ 1, 2, 3, 4, 5 ]

Answer would be [ 2, 1, 1, 1, 1 ]. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> frequencyOfMaxValue(vector<int> numbers, vector<int> q) {
        if(numbers.empty())
            return {};

        // q vector size can be bigger than numbers vector size

        unordered_map<int,int> uoFreq;
        int maxValue = INT_MIN;
        vector<int> retVec;

        for(int index=0;index<q.size();index++) {
            uoFreq.clear();
            maxValue = INT_MIN;
            for(int i=index;i<numbers.size();i++) {
                uoFreq[numbers[i]]++;
                maxValue = max(maxValue,numbers[i]);
            }
            if(uoFreq.end() != uoFreq.find(maxValue))
                retVec.push_back(uoFreq.find(maxValue)->second);
            else
                retVec.push_back(0);
        }

        return retVec;
    }
};

int main() {
    vector<int> numbers = {5,4,5,3,2};
    vector<int> q = {1,2,3,4,5};
    Solution sol;
    auto freqVec = sol.frequencyOfMaxValue(numbers,q);
    for(auto i: freqVec)
        cout << i << "\t";
    cout << endl;
    return 0;
}