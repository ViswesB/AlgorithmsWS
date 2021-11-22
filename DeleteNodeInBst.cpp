/*
450. Delete Node in a BST
Medium

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:

Input: root = [], key = 0
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -105 <= Node.val <= 105
    Each node has a unique value.
    root is a valid binary search tree.
    -105 <= key <= 105

 

Follow up: Could you solve it with time complexity O(height of tree)?

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        //case 1: if node is leaf
        //case 2: if node is with one child
        //case 3: if node is with two children
        if(key < root->val) 
            root->left = deleteNode(root->left,key);
        else if(key > root->val)
            root->right = deleteNode(root->right,key);
        else {
            //found node
            //node is leaf
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if(!root->left && root->right) {
                auto temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            else if(root->left && !root->right) {
                auto temp = root->left;
                delete root;
                root = temp;
                return root;
            }
            else {
                //has both children
                //go to right node and keep going to left
                auto temp = root->right;
                while(temp->left) {
                    temp = temp->left;
                }
                root->val = temp->val;
                //now delete node on right subtree
                root->right = deleteNode(root->right,root->val);
                return root;
            }
        }
        return root;
    }

    void inorderTraversal(TreeNode* root) {
        if(!root)
            return;
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    unique_ptr<Solution> sol = make_unique<Solution>();

    TreeNode* p = root->left->left->right;
    sol->inorderTraversal(root);
    cout << endl;
    root = sol->deleteNode(root,3);
    //inorder traversal
    sol->inorderTraversal(root);
    return 0;
}