/*
653. Two Sum IV - Input is a BST
Easy

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Example 3:

Input: root = [2,1,3], k = 4
Output: true

Example 4:

Input: root = [2,1,3], k = 1
Output: false

Example 5:

Input: root = [2,1,3], k = 3
Output: true

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -104 <= Node.val <= 104
    root is guaranteed to be a valid binary search tree.
    -105 <= k <= 105
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
#include <vector>
#include <stack>
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
        TreeNode* curr = root;
        stack<TreeNode*> sTree;
        vector<int> inorderVec;
    
        while(curr || !sTree.empty()) {
            while(curr) {
                //keep going left
                sTree.push(curr);
                curr = curr->left;
            }

            curr = sTree.top();
            sTree.pop();
            inorderVec.emplace_back(curr->val);

            curr = curr->right;
        }
        
        return inorderVec;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        if(root && !root->left && !root->right)
            return false;
        
        auto inorderVec = inorderTraversal(root);
        
        //use 2 pointers
        int start = 0;
        int end = inorderVec.size()-1;
        
        while(start < end) {
            if(inorderVec[start] + inorderVec[end] == k)
                return true;
            else if(inorderVec[start] + inorderVec[end] > k)
                end--;
            else if(inorderVec[start] + inorderVec[end] < k)
                start++;
        }
        
        return false;
    }
};