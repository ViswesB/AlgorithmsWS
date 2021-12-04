/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

 

Constraints:

    1 <= word.length, prefix.length <= 2000
    word and prefix consist only of lowercase English letters.
    At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

#include <iostream>
#include <memory>
#include <map>
#include <string>
using namespace std;

class TrieNode {
public:
    bool isWordEnd;
    map<char,TrieNode*> next;
    TrieNode() {
        isWordEnd = false;
    }
};

class Trie {
private: 
    //head of TrieNode
    TrieNode* root = nullptr;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        //insert into trieNode every char from word
        TrieNode* node = root;

        for(int i=0;i<word.size();++i) {
            //check if child node exists with word
            //if not create
            if((node->next).count(word[i]) <= 0) {
                (node->next).insert(make_pair(word[i],new TrieNode()));
            }
            //else access it
            node = (node->next)[word[i]];
        }
        //mark end node as wordEnd true
        node->isWordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        //check every character
        for(int i=0;i<word.size();++i) {
            //if character dont exist then return false;
            if((node->next).count(word[i]) <= 0)
                return false;
            node = (node->next)[word[i]];
        }

        //reached end of searchable word, return TrieNode's wordEnd Status
        return node->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        //check every character
        for(int i=0;i<prefix.size();++i) {
            //if character dont exist then return false;
            if((node->next).count(prefix[i]) <= 0)
                return false;
            node = (node->next)[prefix[i]];
        }

        //reached end of prefix word , so prefix exists
        return true;
    }
};

int main() {
    unique_ptr<Trie> trie = make_unique<Trie>();
    trie->insert("apple");
    cout << boolalpha << trie->search("apple") << endl;   // return true
    cout << boolalpha << trie->search("app") << endl;    // return false
    cout << boolalpha << trie->startsWith("app") << endl; // return true
    trie->insert("app");
    cout << boolalpha << trie->search("app") << endl;  // return true
    return 0;
}