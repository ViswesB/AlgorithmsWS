/*
92. Reverse Linked List II
Medium

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n

 
Follow up: Could you do it in one pass?
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x,ListNode* nxt):val(x), next(nxt){}
};

class SLL {
private:
    ListNode* head;
public:
    ~SLL()
    {
        destroySLL();
    }

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

    void destroySLL()
    {
        ListNode* node = head;
        while(!node)
        {
            delete node->next;
            delete node;
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

    /* Returns length of Linked List */
    int len(ListNode* node) {
        int count = 0;
        while(node) {
            count++;
            node = node->next;
        }
        return count;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;
        
        if(left > right || left == right)
            return head;
        
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;
        ListNode* currNode = head;
        ListNode* prev = nullptr;

        // O(n) to find left and right
        while(currNode) {
            if(currNode->val == left)
                leftNode = currNode;
            else if(currNode->val == right)
                rightNode = currNode;

            // loop iterator
            currNode = currNode->next;
        }

        // if left and right dont exist in LL then return head
        if(!leftNode && !rightNode)
            return head;
        else if (leftNode && rightNode) {
            // if left and right elements are neighbours nothing to reverse return head
            if(leftNode->next == rightNode)
                return head;
        }
        
        currNode = head;
        // //O(m) to reverse
        while(currNode) {
            cout << currNode << "\t" << leftNode << "\t" << rightNode << endl;
            if(currNode != leftNode) {
                currNode = currNode->next;
            }
            else {
                cout << " should be reversed here " << endl;
                ListNode* next = currNode->next;
                currNode->next = prev;
                prev = currNode;
                currNode = next;
            }
        }
        return head;
    }
};

int main()
{
    SLL sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,1);
    ll = sll.append(ll,2);
    ll = sll.append(ll,3);
    ll = sll.append(ll,4);
    ll = sll.append(ll,5);
    ll = sll.append(ll,6);
    // ll = sll.append(ll,2);
    

    sll.PrintSLL(ll);
    auto revBWLL = sll.reverseBetween(ll,2,5);
    if(revBWLL)
        sll.PrintSLL(revBWLL,true);
    return 0;
}