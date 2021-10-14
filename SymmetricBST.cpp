/*
*/
#include <iostream>
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return false;
        
        if(root && !root->left && !root->right)
            return true;

        if(root && !root->left && root->right)
            return false;
        
        if(root && root->left && !root->right)
            return false;
        
        stack<TreeNode*> lStack;
        stack<TreeNode*> rStack;
        lStack.push(root);
        rStack.push(root);
        TreeNode* lCurr = root->left;
        TreeNode* rCurr = root->right;
        
        while(!lStack.empty() && !rStack.empty()) {
            //Keep traversing left curr to left till it reaches end
            while(lCurr) {
                lStack.push(lCurr);
                lCurr = lCurr->left;
            }

            //Keep traversing right curr to right till it reaches end
            while(rCurr) {
                rStack.push(rCurr);
                rCurr = rCurr->right;
            }

            // here both lCurr and rCurr should be pointing to nullptr
            if((lStack.top()->right == nullptr) && (rStack.top()->left == nullptr)) {
                // pick top on both stacks to compare
                lCurr = lStack.top();
                lStack.pop();
                rCurr = rStack.top();
                rStack.pop();

                //compare values
                if(lCurr->val != rCurr->val) {
                    return false;
                }
            }
            
            //move from child nodes to parent node
            // auto lStackRight = 
            // if(!lStack.top()->right && !rStack.top()->left) {
            //     lCurr = lStack.top();
            //     lStack.pop();
            //     rCurr = rStack.top();
            //     rStack.pop();
            // }

            while(!lStack.empty() && lStack.top()->right == lCurr && 
                  !rStack.empty() && rStack.top()->left == rCurr) {
                lCurr = lStack.top();
                lStack.pop();
                rCurr = rStack.top();
                rStack.pop();
                //compare values
                if(lCurr->val != rCurr->val) {
                    return false;
                }
            }
        
            // check have we reached top of root in stack
            if(lStack.top() == root && rStack.top() == root)
                return true;

            if(!lStack.empty())
                lCurr = lStack.top()->right;

            if(!rStack.empty())
                rCurr = rStack.top()->left;
        }
        return true;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = new TreeNode(1) ;
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = nullptr;
    root->right->right = new TreeNode(3);
    root->right->left = nullptr;
    
    Solution sol;
    cout << boolalpha << sol.isSymmetric(root) << endl;
    return 0;
}