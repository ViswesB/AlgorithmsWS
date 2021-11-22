/*
285. Inorder Successor in BST
Medium

1830

74

Add to List

Share
Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
All Nodes will have unique values.
Accepted
231,521
Submissions
508,780
*/

#include <iostream>
#include <memory>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ancestor = nullptr;
        
        if(!p)
            return p;
        
        while(root) {
            if(root->val <= p->val) {
                root = root->right;
            }
            else if (root->val >= p->val){
                ancestor = root;
                root= root->left;
            }
        }
        
        return ancestor;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(5);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(10);
    root->right->right->right = new TreeNode(12);
    unique_ptr<Solution> sol = make_unique<Solution>();

    TreeNode* p = root->left->left->right;

    TreeNode* ans = sol->inorderSuccessor(root,p);
    cout << ans->val << endl;
    return 0;
}