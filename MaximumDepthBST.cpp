/*
*/

#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode* root) {
         if(!root)
            return 0;
        
        if(root && !root->left && !root->right)
            return 1;
        // using BFS
        queue<TreeNode*> treeQ;
        TreeNode* curr = nullptr;
        treeQ.push(root);
        int depth = 0;
        int len = 0;
        
        while(!treeQ.empty()) {
            len = treeQ.size();
            
            while(len > 0) {
                curr = treeQ.front();
                treeQ.pop(); 
                len--;
                if(curr) {
                    if(curr->left)
                        treeQ.push(curr->left);
                    if(curr->right)
                        treeQ.push(curr->right);
                }
            }
            
            if(!len)
                depth++;
        }
        
        return depth;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(1) ;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    Solution sol;
    auto maxDepth = sol.maxDepth(root);
    cout << "max depth of BST is: " << maxDepth << endl;
    return 0;
}