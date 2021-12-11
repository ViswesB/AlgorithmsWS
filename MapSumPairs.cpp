/*
map sum pairs
677. Map Sum Pairs
Medium

Design a map that allows you to do the following:

    Maps a string key to a given value.
    Returns the sum of the values that have a key with a prefix equal to a given string.

Implement the MapSum class:

    MapSum() Initializes the MapSum object.
    void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
    int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

 

Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

 

Constraints:

    1 <= key.length, prefix.length <= 50
    key and prefix consist of only lowercase English letters.
    1 <= val <= 1000
    At most 50 calls will be made to insert and sum.

Accepted
79,751
Submissions
140,203
*/

#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

class TrieNode {
public:
    bool wordEnd;
    int value;
    unordered_map<char,TrieNode*> next;
    TrieNode() : wordEnd(false) {}
    TrieNode(bool we,int val) : wordEnd(we), value(val) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word,const int& value) {
        TrieNode* node = root;
        for(int i=0;i<word.size();++i) {
            //verify if char already exists
            //if not create
            if((node->next).count(word[i]) <= 0) {
                (node->next).insert(make_pair(word[i],new TrieNode(false,value)));
                node = (node->next)[word[i]];
            }
            else {
            //else move to node
                node = (node->next)[word[i]];
                node->value += value;
            }
        }
        //mark as wordend
        node->wordEnd = true;
    }
    
    pair<bool,int> isPrefix(const string& prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();++i) {
            //verify if char exists or not
            if((node->next).count(prefix[i]) <= 0)
                return make_pair(false,0);
            //move to that node
            node = (node->next)[prefix[i]];
        }
        return make_pair(true,node->value);
    }
};

class MapSum {
private:
    unique_ptr<Trie> trie;
    unordered_map<string,int> hashMapStr;
public:
    MapSum() {
        trie = make_unique<Trie>();
    }
    
    void insert(string key, int val) {
        //update hashMap
        auto hashRet = hashMapStr.insert(make_pair(key,val));
        if(hashRet.second)
            trie->insert(key,val);
        else {
            int prev = hashMapStr[key];
            hashMapStr[key] = val;
            trie->insert(key,val - prev);
        }
    }
    
    int sum(string prefix) {
        auto ret = trie->isPrefix(prefix);
        return ret.second;
    }
};

int main() {
    unique_ptr<MapSum> mp = make_unique<MapSum>();
    mp->insert("apple", 3);  
    cout << mp->sum("ap") << endl;
    mp->insert("app",2);
    cout << mp->sum("ap") << endl;
    return 0;
}