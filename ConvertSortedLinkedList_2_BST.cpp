/*
109. Convert Sorted List to Binary Search Tree
Medium

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [0]
Output: [0]

Example 4:

Input: head = [1,3]
Output: [3,1]
*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution {
    private:
    ListNode* head;
    public:
    ListNode* append(ListNode* head,int x)
    {
        //remembering last address
        ListNode* last = head;
        ListNode* node = new ListNode(x);
        // head is null which means we have created first element
        if(!head) {
            head = node;
        }
        else {
            //Moving pointer to end of list
            while(last->next){ 
                last = last->next;
            }
            last->next = node;
        }
        return head;
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

    void PrintSLL(ListNode* node, bool addAddress=false)
    {
        while(node!=nullptr)
        {
            if(addAddress)
                cout << " | " << node->val << "  " << node << " | " << " --> ";
            else
                cout << node->val << " -->  ";
            node = node->next;
        }
        if(node == nullptr)
            cout << "null";
        cout << endl;
    }

    ListNode* getMidNodeFromLinkedList(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        ListNode* prev = node;

    
        while(fast && fast->next) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
            fast = fast->next;
        }

        //prev is required to updated left subtree to point to null
        //this will act as loop breaking statement in recursion
        if(prev)
            prev->next = nullptr;

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* treeNode = nullptr;
        if(!head)
            return nullptr;

        if(!head->next)
            return new TreeNode(head->val);
        

        ListNode* nodeToBeInserted = getMidNodeFromLinkedList(head);
        if(head == nodeToBeInserted)
            return treeNode;

        treeNode = new TreeNode(nodeToBeInserted->val);
        treeNode->left = sortedListToBST(head);
        treeNode->right = sortedListToBST(nodeToBeInserted->next);
        return treeNode;
    }
};

int main()
{
    solution sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,-10);
    ll = sll.append(ll,-3);
    ll = sll.append(ll,0);
    ll = sll.append(ll,5);
    ll = sll.append(ll,9);

    sll.PrintSLL(ll);

    auto tree = sll.sortedListToBST(ll);
    if(tree)
        sll.PrintTreeNode(tree);
    return 0;
}