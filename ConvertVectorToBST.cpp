/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.

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

class TreeNode {
public:
    TreeNode(): val(0),left(nullptr),right(nullptr) {root = nullptr;};
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {root = nullptr;};
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {root = nullptr;}

    ~TreeNode()
    {
        destroyBST();
    }  

    TreeNode* getRoot() {
        return root;
    }

    void destroyBST()
    {
        destroyBST(getRoot());
    }

    void Insert(int x)
    {
        if(root == nullptr)
            root = Allocate(x);
        else {
            if(x < root->val)
            {
                root->left = Insert(root->left,x);
            }
            else if(x > root->val)
            {
                root->right = Insert(root->right,x);
            }
        }
    }

    TreeNode* Allocate(int x)
    {
        TreeNode* node = new TreeNode(x);
        return node;
    }

    void PrintBST()
    {
        PrintBST(getRoot());
    }

// private:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* root;

    void destroyBST(TreeNode* node)
    {
        if(node != nullptr) {
            destroyBST(node->left);
            destroyBST(node->right);
            delete node;
        }
        node = nullptr;
    }

    TreeNode* Insert(TreeNode* node, int x)
    {
        if(node == nullptr)
        {
            node = Allocate(x);
        }
        // Node already exists check should it be left or right
        else if(x < node->val)
            node->left = Insert(node->left,x);
        else if (x > node->val)
            node->right = Insert(node->right,x);
        return node;
    }

    void PrintBST(TreeNode* node)
    {
        if(node != nullptr) 
        {
            PrintBST(node->left);
            cout << node->val << "\t";
            PrintBST(node->right);
        }
    }
};

class Solution
{
public:
    TreeNode* createNodeRecursion(vector<int>& nums,int low,int high)
 
    {
        cout << "Low:" << low << " high:" << high << endl;
        if( low > high)
            return nullptr;

        int mid = (low+high)/2;
        cout << "mid:" << mid << endl;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createNodeRecursion(nums,low,mid-1);
        node->right = createNodeRecursion(nums,mid+1,high);
        return node;
    }
    

    TreeNode* createNodeIterative(vector<int>& nums)
    {
        int low = 0;
        int high = (nums.size()-1);
        int mid = (low+high)/2;

        //Create Root Node 
        TreeNode* node = new TreeNode(nums[mid]);

        //create all elements on left of node
        for(int i=low;i<mid;i++)
        {
            cout << "for left:" << nums[i] << endl;
            if(!node->left)
                node->left = new TreeNode(nums[i]);
            else if(node->left && nums[i] < node->left->val)
                node->left = new TreeNode(nums[i],node->left,nullptr);
        }

        for(int j=mid+1;j<=high;j++)
        {
            cout << "for right:" << nums[j] << endl;
            if(!node->right) {
                cout << "right doesnt exist" << endl;
                node->right = new TreeNode(nums[j]);
            }
            else if(node->right && nums[j] > node->right->val)
                node->right = new TreeNode(nums[j],nullptr,node->right);
        }

        return node;
    }

    void PrintBST(TreeNode* node)
    {
        if(node != nullptr) 
        {
            cout << node->val << "\t";
            PrintBST(node->left);
            PrintBST(node->right);
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        cout << "nums size: " << nums.size() << endl;
        return createNodeIterative(nums);
    }
};

int main()
{
    TreeNode tn;
    Solution sol;
    vector<int> vec = {-10,-3,0,5,9};
    auto rootNode = sol.sortedArrayToBST(vec);
    sol.PrintBST(rootNode);
    // tn.Insert(0);
    // tn.Insert(-3);
    // tn.Insert(5);
    // tn.Insert(-10);
    // tn.Insert(9);
    // tn.PrintBST();
    return 0;
}