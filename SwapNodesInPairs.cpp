/*
24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]

 

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100

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

    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        
        if(!head->next)
            return head;

        int nodeCount = 1;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* prevsPrev = nullptr;
        ListNode* next = nullptr;

        while(curr) {            
            if(nodeCount % 2 == 0) {
                //perform swap
                next = curr->next;
                prev->next = next;
                curr->next = prev;
                //reset head only if first element got updated
                // swapping every 2nd element, so for first pair n == 1
                if(nodeCount - 1 == 1)
                    head = curr;
                if(prevsPrev)
                    prevsPrev->next = curr;    
                prevsPrev = curr;
                curr = next;
            }
            else {
                prevsPrev = prev;
                prev = curr;
                curr = curr->next; 
            }
            nodeCount++;
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

    sll.PrintSLL(ll);
    auto swapLL = sll.swapPairs(ll);
    if(swapLL)
        sll.PrintSLL(swapLL);
    return 0;
}