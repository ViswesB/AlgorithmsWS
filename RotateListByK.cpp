/*
61. Rotate List
Medium

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

 

Constraints:

    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109

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

    ListNode* getLastElem(ListNode* head,ListNode** prev)
    {
        ListNode* lastElem = head;
        while(lastElem->next) {
            *prev = lastElem;
            // cout << "prev->val: " << *prev->val << endl;
            lastElem = lastElem->next;
        }
        return lastElem;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        
        if(!head->next)
            return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* first = nullptr;
        ListNode* last = nullptr;

        //get length of linked list
        auto length = len(curr);
        
        //get the number of moves need to be made from length and k
        int totalMoves = 0;
        if(k >= length)
            totalMoves = k % length;
        else
            totalMoves = k;

        // if totalMoves is 0 then no need to rotate
        if(totalMoves == 0)
            return head;

        first = curr;
        // cout << totalMoves << endl;
        while(curr && totalMoves > 0) {    
            last = getLastElem(head,&prev);
            totalMoves--;
            // cout << "last->val: " << last->val << "\t" << "prev->val: " << prev->val << " rotate by: " << totalMoves << endl;
            prev->next = last->next;
            last->next = first;
            curr = last;
            head = curr;
            first = curr;
            // cout << "curr->val: " << curr->val << endl;
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
    auto rotateLL = sll.rotateRight(ll,7);
    if(rotateLL)
        sll.PrintSLL(rotateLL);
    return 0;
}