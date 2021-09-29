/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
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
                cout << " | " << node->val << "  " << node->next << " | " << " --> ";
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)
            return head;

        if(!head)
            return nullptr;
        
        // Only single element in ll
        if(!head->next) {
            if(n > 1)
                return nullptr;
            else 
                return nullptr;
        }
    
        ListNode* curr = head;

        //get length of ll
        int iLen = len(curr);
        auto currNodeCount = 1;
        auto tempCount = iLen - (n-1);
        ListNode* prev = nullptr;

        while (curr)
        {
            if(currNodeCount == tempCount)
            {
                // First node to be deleted
                if(!prev) {
                    ListNode* next = curr->next;
                    curr->next = nullptr;
                    delete curr;
                    curr = next;
                    head = curr;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev;
                }
                break;
            }
            prev = curr;
            currNodeCount++;
            curr = curr->next;
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

    // Delete nth node which is end node of ll
    sll.PrintSLL(ll);
    cout << " deleting end node" << endl;
    auto deletell = sll.removeNthFromEnd(ll,1);
    if(deletell)
        sll.PrintSLL(deletell);
    
    cout  << "-------------------" << endl;
    sll.PrintSLL(deletell);
    cout << " deleting first node" << endl;
    // Delete nth node which would be first node in ll
    deletell = sll.removeNthFromEnd(deletell,5);
    if(deletell)
        sll.PrintSLL(deletell);

    cout << " deleting node anywhere between first and last" << endl;
    // Delete nth node which would be any other node in between
    deletell = sll.removeNthFromEnd(deletell,2);
    if(deletell)
        sll.PrintSLL(deletell);
    return 0;
}