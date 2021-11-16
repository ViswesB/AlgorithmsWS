/*
692. Top K Frequent Words
Medium

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

 

Constraints:

    1 <= words.length <= 500
    1 <= words[i] <= 10
    words[i] consists of lowercase English letters.
    k is in the range [1, The number of unique words[i]]


Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Solution {
    struct element {
        string word;
        int freq;
        element(string w,int f): word(w),freq(f) {}
    };
    
    struct elemComparator {
        bool operator() (const element& lhs,const element& rhs) {
            if(lhs.freq != rhs.freq) 
                return lhs.freq > rhs.freq;
            else {
                //2 words having same freq
                //sort by lexicographical order
                return lhs.word.compare(rhs.word) < 0;
            }
        }
    };
    
    priority_queue<element,vector<element>,elemComparator> minHeap;
    unordered_map<string,int> uoWordFreq;
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        for(string word:words) {
            uoWordFreq[word] += 1;
        }

        //heapify
        for(auto itr=uoWordFreq.begin();itr!=uoWordFreq.end();itr++) { 
            minHeap.push(element(itr->first,itr->second));
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        while(k!=0) {
            k--;
            auto elem = minHeap.top();
            minHeap.pop();
            ans.emplace_back(elem.word);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    // vector<string> words = {"aaa","aa","a"};
    int k = 2;
    auto topFreq = sol->topKFrequent(words,k);
    for(string word: topFreq)
        cout << word << endl;
    return 0;
}