/*
Inorder Tree Traversal
*/

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
            
        vector<int> inTreeTraverse;
        stack<TreeNode*> treeStack;
        TreeNode* curr = root;

        while(curr || !treeStack.empty()) {
           while(curr) {
               treeStack.push(curr);
               curr = curr->left;
           }

           //before this curr reached end of left
           curr = treeStack.top();
           treeStack.pop();

           inTreeTraverse.push_back(curr->val);

           curr = curr->right;
        }
        
        return inTreeTraverse;
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
    auto inOrderVec = sol.inorderTraversal(root);
    for(auto i:inOrderVec)
        cout << i << "\t";
    cout << endl;
    return 0;
}