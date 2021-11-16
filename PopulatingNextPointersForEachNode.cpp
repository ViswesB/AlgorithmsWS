/*
116. Populating Next Right Pointers in Each Node
Medium

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 212 - 1].
    -1000 <= Node.val <= 1000

 

Follow-up:

    You may only use constant extra space.
    The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

Accepted
593,323
Submissions
1,112,660
*/

#include <iostream>
#include <queue>
#include <memory>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;   

        Node* curr = nullptr;
        queue<Node*> qNode;
        qNode.push(root);
        int len = 0;

        while(!qNode.empty()) {
            len = qNode.size();
            Node* prev = nullptr;
            while(len--) {
                curr = qNode.front();
                qNode.pop();
                curr->next = prev;
                prev=curr;

                if(curr->right)
                    qNode.push(curr->right);
                if(curr->left)
                    qNode.push(curr->left);
            }
        }

        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    unique_ptr<Solution> sol = make_unique<Solution>();
    auto nextNode = sol->connect(root);
    while(nextNode) {
        if(!nextNode->next)
            cout << "#" << ", ";
        else
            cout << nextNode->val << ", ";
        nextNode = nextNode->next;
    }

    cout << endl;
    return 0;
}