/*
226. Invert Binary Tree
Easy

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

*/

#include <bits/stdc++.h>
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        
        queue<TreeNode*> qTree;
        qTree.push(root);
        TreeNode* curr = nullptr;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        int lenTN = 0;

        while(!qTree.empty()) {
            lenTN = qTree.size();

            while(lenTN != 0) {
                curr = qTree.front();
                qTree.pop();
                lenTN--;
                //swap
                auto temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
                if(curr->left)
                    qTree.push(curr->left);
                if(curr->right)
                    qTree.push(curr->right);
            }
        }
        return root;
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
    auto treeNode = sol.invertTree(root);

    if(treeNode) {
        cout << treeNode->val << endl;
        if(treeNode->left)
        cout << treeNode->left->val << endl;
        else 
        cout << "nullptr" << endl;
        if(treeNode->right)
        cout << treeNode->right->val << endl;
        else 
        cout << "nullptr" << endl;
        if(treeNode->left->left)
        cout << treeNode->left->left->val << endl;
        else 
        cout << "nullptr" << endl;
        if(treeNode->left->right)
        cout << treeNode->left->right->val << endl;
        else 
        cout << "nullptr" << endl;
        if(treeNode->right->left)
        cout << treeNode->right->left->val << endl;
        else 
        cout << "nullptr" << endl;
        if(treeNode->right->right)
        cout << treeNode->right->right->val << endl;
        else 
        cout << "nullptr" << endl;
    }
    
    return 0;
}
