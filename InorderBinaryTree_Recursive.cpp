/*
Given the root of a binary tree, return the inorder traversal of its nodes values.
 

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,2]
Output: [2,1]

Example 5:

Input: root = [1,null,2]
Output: [1,2]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 
Follow up: Recursive solution is trivial, could you do it iteratively?
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

#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    TreeNode():val(0),left(nullptr),right(nullptr) {root = nullptr;}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {root = nullptr;}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {root = nullptr;}

    ~TreeNode()
    {
        destroyTreeNode();
    }

    void Insert(int* val)
    {
        if(root == nullptr)
            root = Allocate(val);
        else if(root->left == nullptr)
            root->left = Insert(root->left,val);
        else if(root->right == nullptr)
            root->right = Insert(root->right,val);
    }


    void destroyTreeNode()
    {
        destroyTreeNode(root);
    }

    TreeNode* getRoot()
    {
        return root;
    }

    void PrintTreeNode()
    {
        PrintTreeNode(root);
    }

// private:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* root;

    TreeNode* Allocate(int* val)
    {
        TreeNode* node = new TreeNode(*val);
        return node;
    }

    TreeNode* Insert(TreeNode* node, int* val)
    {
        if(node == nullptr)
            node = Allocate(val);
        else if(node->left == nullptr) {
            // if(val == nullptr) 
            //     node->left = nullptr;
            if(val != nullptr)
                node->left = Insert(node->left,val);
        }
        else if(node->right == nullptr) {
            // if(val == nullptr)
            //     node->right = nullptr;
            if(val != nullptr)
                node->right = Insert(node->right,val);
        }
        return node;
    }

    void destroyTreeNode(TreeNode* node)
    {
        if(node != nullptr)
        {
            destroyTreeNode(node->left);
            destroyTreeNode(node->right);
            delete node;
            node = nullptr;
        }
    }

    void PrintTreeNode(TreeNode* node)
    {
        if(node != nullptr) 
        {
            PrintTreeNode(node->left);
            cout << node->val << "\t";
            PrintTreeNode(node->right);
        }
    }
};

class Solution
{
    public:
    void PrintTreeNode(TreeNode* node)
    {
        if(node != nullptr) 
        {
            PrintTreeNode(node->left);
            cout << node->val << "\t";
            PrintTreeNode(node->right);
        }
    }

    void UpdateVecforInOrderTraversal(TreeNode* node,vector<int>& vec)
    {
        if(node != nullptr)
        {
            UpdateVecforInOrderTraversal(node->left,vec);
            vec.push_back(node->val);
            UpdateVecforInOrderTraversal(node->right,vec);
        }
    }
    
    void UpdateVecforPreOrderTraversal(TreeNode* node,vector<int>& vec)
    {
        if(node != nullptr)
        {
            vec.push_back(node->val);
            UpdateVecforPreOrderTraversal(node->left,vec);
            UpdateVecforPreOrderTraversal(node->right,vec);
        }
    }

    void UpdateVecforPostOrderTraversal(TreeNode* node,vector<int>& vec)
    {
        if(node != nullptr)
        {
            UpdateVecforPostOrderTraversal(node->left,vec);
            UpdateVecforPostOrderTraversal(node->right,vec);
            vec.push_back(node->val);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ioTreeTraverse;
        UpdateVecforInOrderTraversal(root,ioTreeTraverse);
        return ioTreeTraverse;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preTreeTraverse;
        UpdateVecforPreOrderTraversal(root,preTreeTraverse);
        return preTreeTraverse;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postTreeTraverse;
        UpdateVecforPostOrderTraversal(root,postTreeTraverse);
        return postTreeTraverse;
    }
};

int main()
{
    TreeNode tn;
    int* pVal = new int();
    *pVal = 1;
    tn.Insert(pVal);
    tn.Insert(nullptr);
    *pVal = 2;
    tn.Insert(pVal);
    *pVal = 3;
    tn.Insert(pVal);
    // tn.PrintTreeNode();
    Solution sol;
    auto vec = sol.inorderTraversal(tn.getRoot());
    for(auto i:vec)
        cout << i << "\t";
    cout << endl;
    delete pVal;
    return 0;
}