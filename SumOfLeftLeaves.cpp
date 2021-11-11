/*
404. Sum of Left Leaves
Easy

Given the root of a binary tree, return the sum of all left leaves.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -1000 <= Node.val <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    int m_sum = 0;
public:
    void leftSumRec(TreeNode* curr,bool isLeftNode) {
        if(!curr)
            return;
        
        //left and leaf
        if(isLeftNode && !curr->left && !curr->right) {
            m_sum += curr->val;
            return;
        }
        
        leftSumRec(curr->left,true);
        leftSumRec(curr->right,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        leftSumRec(root,false);
        return m_sum;
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol->sumOfLeftLeaves(root) << endl;
    delete root;
    return 0;
}