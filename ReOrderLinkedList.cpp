/*
143. Reorder List
Medium

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

 

Constraints:

    The number of nodes in the list is in the range [1, 5 * 104].
    1 <= Node.val <= 1000

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

    void reorderList(ListNode* head) {
        /* Algorithm using extra space */ 
        if(!head || !head->next)
            return;

        if(!head->next->next)
            return;

        ListNode* ll = head;
        ListNode* reverseLL = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        //First Pass for mid node
        while(fast && fast->next) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
            if(fast)
                fast = fast->next;
        }

        prev->next = nullptr;
        reverseLL = slow;

        // we have now 2 linkedlist 
        // say l1 = 1->2->3->4->null
        // say l2 = 5->6->7->8->null
        // reverse l2
        prev = nullptr;
        while(reverseLL) {
            next = reverseLL->next;
            reverseLL->next = prev;
            prev = reverseLL;
            reverseLL = next;
        }
        reverseLL = prev;
        
        //post reverse we have
        // l1 = 1->2->3->4->null
        // l2 = 5->6->7->8->null
        // l1 = 1->5->2->3->4->null
        // l2 = 6->7->8->null
        prev = nullptr;
        next = nullptr;

        while(ll && reverseLL) {
            next = ll->next;
            auto rNext = reverseLL->next;
            reverseLL->next = nullptr;
            ll->next = reverseLL;
            reverseLL->next = next;
            //next could be null 
            if(next)
                ll = next;
            else
                ll = reverseLL;
            reverseLL = rNext;
        }
        return;
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
    ll = sll.append(ll,7);
    ll = sll.append(ll,8);

    sll.PrintSLL(ll,true);
    sll.reorderList(ll);
    cout << "REORDERED LIST IS:" << endl;
    sll.PrintSLL(ll);
    return 0;
}