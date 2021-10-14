/*
199. Binary Tree Right Side View
Medium

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100


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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        if(root && !root->right && !root->left)
            return {root->val};
        
        queue<TreeNode*> qTree;
        TreeNode* curr = root;
        vector<int> rightSideVec;
        int lenTree = 0;
        qTree.push(root);
        int rightViewValue = 0;
        
        while(!qTree.empty()) {
            lenTree = qTree.size();
            
            while(lenTree) {
                lenTree--;
                curr = qTree.front();
                qTree.pop();
                rightViewValue = curr->val;
                if(curr->left)
                    qTree.push(curr->left);
                if(curr->right) {
                    qTree.push(curr->right);
                }
            }                
            
            if(lenTree == 0) {
                rightSideVec.push_back(rightViewValue);
            }
        }
        
        return rightSideVec;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(1) ;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = nullptr;
    root->left->right = new TreeNode(4);
    root->right->left = nullptr;
    root->right->right = nullptr;
    
    Solution sol;
    auto rightSideVec = sol.rightSideView(root);
    for(auto i:rightSideVec)
        cout << i << "\t";
    cout << endl;
    return 0;
}