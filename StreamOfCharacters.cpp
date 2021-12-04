/*
1032. Stream of Characters
Hard

Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

    StreamChecker(String[] words) Initializes the object with the strings array words.
    boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.

 

Example 1:

Input
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
Output
[null, false, false, false, true, false, true, false, false, false, false, false, true]

Explanation
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // return False
streamChecker.query("b"); // return False
streamChecker.query("c"); // return False
streamChecker.query("d"); // return True, because 'cd' is in the wordlist
streamChecker.query("e"); // return False
streamChecker.query("f"); // return True, because 'f' is in the wordlist
streamChecker.query("g"); // return False
streamChecker.query("h"); // return False
streamChecker.query("i"); // return False
streamChecker.query("j"); // return False
streamChecker.query("k"); // return False
streamChecker.query("l"); // return True, because 'kl' is in the wordlist

 

Constraints:

    1 <= words.length <= 2000
    1 <= words[i].length <= 2000
    words[i] consists of lowercase English letters.
    letter is a lowercase English letter.
    At most 4 * 104 calls will be made to query.

Accepted
56,122
Submissions
113,425
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <memory>
using namespace std;

class TrieNode {
public:
    bool endOfWord;
    map<char,TrieNode*> next;
    TrieNode() { endOfWord = false;}
};

class Trie {
private:
    //head of Trie
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& word) {
        TrieNode* node = root;
        //insert word into trie in reverse order
        for(int i=word.size()-1;i>=0;i--) {
            //check if char exists in Trie
            //if not
            if((node->next).count(word[i]) <= 0) {
                //create node
                (node->next).insert(make_pair(word[i],new TrieNode()));
            }
            //already exists
            node = (node->next)[word[i]];
        }
        node->endOfWord = true;
    }
    
    bool search(deque<char>& dQ) {
        TrieNode* node = root;
        //using dQ search 
        for(auto itr=dQ.begin();itr!=dQ.end();itr++) {
            //search for character and not found return false
            if((node->next).count(*itr) <= 0) {
                return false;
            }
            //else move to child
            node = (node->next)[*itr];
            //check if reached end of word
            if(node->endOfWord)
                return node->endOfWord;
        }
        
        return false;
    }
};

//using Trie Data structure
class StreamChecker {
private:
    unique_ptr<Trie> trie = make_unique<Trie>();
    deque<char> dQ;
public:
    StreamChecker(vector<string>& words) {
        for(string& w: words) {
            trie->insert(w);
        }
    }
    
    //use deque to insert at front
    //this was we can search in search in reverse
    //for example query "a" then query "b" --> 
    //this should be in order "ba"
    //use this to search as prefix in Trie
    bool query(char letter) {
        dQ.push_front(letter);
        return trie->search(dQ);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> words = {"cd", "f", "kl"};
    unique_ptr<StreamChecker> streamChecker = make_unique<StreamChecker>(words);
    cout << boolalpha << streamChecker->query('a') << endl; // return False
    cout << boolalpha << streamChecker->query('b') << endl; // return False
    cout << boolalpha << streamChecker->query('c') << endl; // return False
    cout << boolalpha << streamChecker->query('d') << endl; // return True, because 'cd' is in the wordlist
    cout << boolalpha << streamChecker->query('e') << endl; // return False
    cout << boolalpha << streamChecker->query('f') << endl; // return True, because 'f' is in the wordlist
    cout << boolalpha << streamChecker->query('g') << endl; // return False
    cout << boolalpha << streamChecker->query('h') << endl; // return False
    cout << boolalpha << streamChecker->query('i') << endl; // return False
    cout << boolalpha << streamChecker->query('j') << endl; // return False
    cout << boolalpha << streamChecker->query('k') << endl; // return False
    cout << boolalpha << streamChecker->query('l') << endl; // return True, because 'kl' is in the wordlist
    return 0;
}