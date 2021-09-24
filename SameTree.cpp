/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false

 

Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104


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
#include <stack>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* tn)
    {
        stack<TreeNode*> iStack;
        TreeNode* curr;
        vector<int> vec;
        iStack.push(tn);

        while(!iStack.empty())
        {
            curr = iStack.top();
            iStack.pop();

            vec.push_back(curr->val);

            if(curr->right != nullptr)
                iStack.push(curr->right);

            if(curr->left != nullptr)
                iStack.push(curr->left);
        }
        return vec;
    }

    bool isSameTreeWithoutRecursion(TreeNode* p, TreeNode* q) {
        bool ret = false;
        // auto vp = preorderTraversal(p);
        // auto vq = preorderTraversal(q);
        vector<int> vp = {1,2,3};
        vector<int> vq = {1,2,3};
        if(vp.size() == vq.size()) {
            for(int i=0;i<vp.size();i++)
            {
                if(vp[i] == vq[i]) 
                    ret = true;
                else
                    break;
            }
        }
        return ret; 
    }

    // Using Recursion
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        //If both Node's are empty then return identical
        if((p == nullptr) && (q == nullptr))
            return true;

        // If either p or q is null then not identical
        if (((p) && (!q)) || ((!p) && (q)))
            return false;
        
        // Verify values 
        if(p->val != q->val)
            return false;
        
        //check Left Subtree is identical to right subtree
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }

    bool isSymmetricalIterative(TreeNode* root) {
        queue<TreeNode*>  treeQ;
        TreeNode* leftNode = nullptr;
        TreeNode* rightNode = nullptr;
        // If Root is Null , consider them symmetric
        if(!root)
            return true;
        else{
            treeQ.push(root->left);
            treeQ.push(root->right);
        }

        while(! treeQ.empty())
        {
            leftNode = treeQ.front();
            treeQ.pop();
            rightNode = treeQ.front();
            treeQ.pop();
            //If both nodes are empty, then move on to other elements in queue
            if(!leftNode && !rightNode)
                continue;
            //If one of the node is empty/null then not symmetrical
            if(!leftNode || !rightNode)
                return false;
            
            //compare values of that node and return if not same
            if(leftNode->val != rightNode->val)
                return false;

            treeQ.push(leftNode->left);
            treeQ.push(rightNode->right);
            treeQ.push(leftNode->right);
            treeQ.push(rightNode->left);
        }
    }

    bool compareTwoNodes(TreeNode* leftNode,TreeNode* rightNode)
    {
        //If both nodes are empty return symmetrical
        if(!leftNode && !rightNode)
            return true;
        
        //If one of nodes empty return not symmetrical
        if(!leftNode || !rightNode)
            return false;

        //Compare values
        if(leftNode->val != rightNode->val)
            return false;
        
        //Move on to child nodes of left and right and compare both of them
        return (compareTwoNodes(leftNode->left,rightNode->right) && compareTwoNodes(leftNode->right,rightNode->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return compareTwoNodes(root->left,root->right);
    }
};

int main()
{
    TreeNode tn;
    int* pVal = new int();
    *pVal = 1;
    tn.Insert(pVal);
    *pVal = 2;
    tn.Insert(pVal);
    *pVal = 3;
    tn.Insert(pVal);
    Solution sol;
    cout << boolalpha << "ret is "<< sol.isSameTree(nullptr,nullptr) << endl;
    return 0;
}