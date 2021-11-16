/*
*/

#include <iostream>
#include <queue>
#include <vector>
#include <memory>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        
        queue<Node*> qNode;
        vector<int> subVec;
        vector<vector<int>> ans;
        qNode.push(root);
        int len = 0;
        
        while(!qNode.empty()) {
            len = qNode.size();
            while(len--) {
                Node* temp = qNode.front();
                qNode.pop();
                subVec.emplace_back(temp->val);
                
                for(auto mNode: temp->children)
                    qNode.push(mNode);
            }
            ans.emplace_back(subVec);
            subVec.clear();
        }
        return ans;
    }
};

int main() {
    return 0;
}