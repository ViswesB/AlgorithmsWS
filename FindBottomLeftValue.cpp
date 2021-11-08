/*
513. Find Bottom Left Tree Value
Medium

Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:

Input: root = [2,1,3]
Output: 1

Example 2:

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1

Accepted
151,042
Submissions
235,728
*/
#include <bits/stdc++.h>
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> qTree;
        qTree.push(root);
        TreeNode* curr = nullptr;
        int len = 0;
        int bottomLeft = 0;
        
        while(!qTree.empty()) {
            len = qTree.size();
            while(len!=0) {
                curr = qTree.front();
                qTree.pop();
                if(len == 1) 
                    bottomLeft = curr->val;
                if(curr->right)
                    qTree.push(curr->right);
                if(curr->left)
                    qTree.push(curr->left);
                
                len--;
            }
        }
        
        return bottomLeft;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(3) ;
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    unique_ptr<Solution> sol = make_unique<Solution>();
    cout << sol->findBottomLeftValue(root) << endl;
    return 0;
}