/*
82. Remove Duplicates from Sorted List II
Medium

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.


*/

#include <iostream>
#include <map>
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

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        
        if(!head->next)
            return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* prev2prev = nullptr;
        map<int,ListNode*> orderMap;
        int count = 0;

        while(curr) {
            auto retval = orderMap.insert(pair<int,ListNode*>(curr->val,curr));
            auto next = curr->next;
            if(curr)
                cout << curr->val;
            if(prev)
                cout << "\t" << prev->val;

            cout << endl;
            // Element already existing
            if(!retval.second) {
                // cout << "Element already existing: " << curr->val << endl;
                // auto duplicateFirst = *retval.first;
                // if((!next && duplicateFirst.second) || (duplicateFirst.second->val != next->val)){
                //     cout << "trying to delete first duplicate: " << duplicateFirst.second->val << "\t" << duplicateFirst.second << endl;
                //     cout << "prev: " << prev->val << "\t" << prev << endl;
                //     prev->next = next;
                //     delete duplicateFirst.second;
                // }
                // else {
                //     // cout << 2 << endl;
                //     duplicateFirst.second->next = next;
                // }
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;

                if(prev) {
                    // as its sorted order if we are here prev element should be same
                    // delete prev
                    prev2prev->next = curr
                }
            }
            else {
                cout << "Element Inserted:" << curr->val << "\t" << curr << endl;
                prev2prev = prev;
                prev = curr;
            }
            curr = next;
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
    ll = sll.append(ll,2);
    ll = sll.append(ll,2);
    ll = sll.append(ll,2);
    ll = sll.append(ll,2);
    ll = sll.append(ll,6);

    sll.PrintSLL(ll);
    auto removeDuplicateLL = sll.deleteDuplicates(ll);
    if(removeDuplicateLL)
        sll.PrintSLL(removeDuplicateLL,true);
    return 0;
}