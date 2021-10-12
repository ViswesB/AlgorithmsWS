/*
Level Order Traversal Or Breadth First Search
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        if(root && !root->left && !root->right)
            return {{root->val}};
        
        vector<vector<int>> bfsVecOfVec;
        vector<int> tmpVec;
        TreeNode* curr = nullptr;
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        int levelNodeCount = 0;
        
        while(!treeQ.empty()) {
            levelNodeCount = treeQ.size();
            
            while(levelNodeCount != 0) {
                curr = treeQ.front();
                treeQ.pop();
                levelNodeCount--;
                if(curr) {
                    tmpVec.push_back(curr->val);
                    treeQ.push(curr->left);
                    treeQ.push(curr->right);
                }
            }
            
            //update vector of vectors
            if(tmpVec.size() != 0) {
                bfsVecOfVec.push_back(tmpVec);
                tmpVec.clear();
            }
        }
        
        return bfsVecOfVec;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(1) ;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    auto bfsVec = sol.levelOrder(root);
    for(auto itr:bfsVec) {
        for(auto i: itr)
            cout << i << "\t";
    }

    cout << endl;
    return 0;
}