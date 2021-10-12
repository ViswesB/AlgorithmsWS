/*
PostOrder Binary Tree Traversal
*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
            
        vector<int> postTreeTraverse;
        stack<TreeNode*> treeStack;
        TreeNode* curr = root;

        //neither stack will be with data , also curr could be null
        while(1) {
            //traverse to left
            if(curr) {
                treeStack.push(curr);
                curr = curr->left;
            }
            // if left null then move to right
            else {
                if(treeStack.empty())
                    break;

                if(treeStack.top()->right == nullptr) {
                    //left is nullptr and right is nullptr as well
                    //update vector with root node
                    postTreeTraverse.push_back(treeStack.top()->val);
                    curr = treeStack.top();
                    treeStack.pop();
                }

                //verify if we are on right tree, to avoid go through loop again for root
                //below check and pop
                while(treeStack.size() != 0 && curr == treeStack.top()->right) {
                    postTreeTraverse.push_back(treeStack.top()->val);
                    curr = treeStack.top();
                    treeStack.pop();
                }
                if(!treeStack.empty())
                    curr = treeStack.top()->right;
                else
                    curr = nullptr;
            }
        }
        
        return postTreeTraverse;
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
    auto postOrderVec = sol.postorderTraversal(root);
    for(auto i:postOrderVec)
        cout << i << "\t";
    cout << endl;
    return 0;
}