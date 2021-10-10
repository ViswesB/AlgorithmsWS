/*
Pre-Order Binary Tree to Vector 
*/

#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
            
        vector<int> preTreeTraverse;
        stack<TreeNode*> treeStack;
        TreeNode* curr = root;
        treeStack.push(curr);

        while(curr && !treeStack.empty()) {
            curr = treeStack.top();
            preTreeTraverse.push_back(curr->val);
            treeStack.pop();
            
            if(curr->right) {
                treeStack.push(curr->right);
            }

            if(curr->left) {
                treeStack.push(curr->left);
            }    
        }
        
        return preTreeTraverse;
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
    auto preOrderVec = sol.preorderTraversal(root);
    for(auto i:preOrderVec)
        cout << i << "\t";
    cout << endl;
    return 0;
}