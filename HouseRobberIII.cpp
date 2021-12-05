/*
337. House Robber III
Medium

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:

Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    0 <= Node.val <= 104

Accepted
252,866
Submissions
478,213
*/

#include <iostream>
#include <memory>
#include <utility>
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
    pair<int,int> dfs(TreeNode* root) {
        if(!root)
            return make_pair(0,0);
        
        //every pair is calculation of sum if parent considered or not
        //calculate leftTreePair and rightTreePair
        auto leftTreePair = dfs(root->left);
        auto rightTreePair = dfs(root->right);
        
        //if root/parent considered then val at parent +
        //value of children below where it is not considered
        int withRoot = root->val + leftTreePair.second + rightTreePair.second;
        
        //if parent is not considered then we are considering max among leftTreePair 
        //and rightTreePair.
        //reason on any node there could be chance where we one node on a level is considered
        //while node on same level can be skipped.
        int withOutRoot = max(leftTreePair.first,leftTreePair.second) + 
                            max(rightTreePair.first,rightTreePair.second);
        
        return make_pair(withRoot,withOutRoot);      
    }
public:
    int rob(TreeNode* root) {
        //sumPair is withRoot and withoutRoot
        auto sumPair = dfs(root);
        return max(sumPair.first,sumPair.second);
    }
};

int main() {
    unique_ptr<Solution> sol = make_unique<Solution>();
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(20);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(100);
    root->left->right = nullptr;
    root->right->right = nullptr;
    root->right->left = new TreeNode(1);
    cout << sol->rob(root) << endl;
    return 0;
}