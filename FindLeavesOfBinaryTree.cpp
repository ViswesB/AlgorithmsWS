/*
366. Find Leaves of Binary Tree
Medium

1754

30

Add to List

Share
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 

Example 1:


Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
Accepted
118,055
Submissions
156,384
*/

#include <iostream>
#include <memory>
#include <vector>
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
    //bfs method returns all leaf nodes and updated Tree
    vector<int> bfs(TreeNode* root) {
        queue<TreeNode*> qNode;
        vector<int> leafVal;
        qNode.push(root);
        
        while(!qNode.empty()) {
            auto node = qNode.front();
            qNode.pop();
            auto leftChild = node->left;
            auto rightChild = node->right;
            
            if(leftChild) {
                //check if this left is leaf
                if(!leftChild->left && !leftChild->right){
                    leafVal.emplace_back(leftChild->val);
                    delete node->left;
                    node->left = nullptr;
                }
                else {
                    qNode.push(leftChild);
                }
            }
            
            if(rightChild) {
                //check if right is leaf 
                if(!rightChild->left && !rightChild->right) {
                    leafVal.emplace_back(rightChild->val);
                    delete node->right;
                    node->right = nullptr;
                }
                else 
                    qNode.push(rightChild);
            }     
        }
        return leafVal;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        //idea is to use BFS
        if(!root)
            return {{}};
        
        if(root && !root->left && !root->right)
            return {{root->val}};
        
        vector<vector<int>> ans;
        while(root->left || root->right) {
            ans.emplace_back(bfs(root));
        }
        
        //top of root will still be available
        vector<int> temp;
        temp.emplace_back(root->val);
        ans.emplace_back(temp);
        root = nullptr;
        temp.clear();
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    unique_ptr<Solution> sol = make_unique<Solution>();
    auto leaves = sol->findLeaves(root);
    for(auto leaf: leaves) {
        for(auto val: leaf) {
            cout << val << "\t";
        }
        cout << endl;
    }
    return 0;
}