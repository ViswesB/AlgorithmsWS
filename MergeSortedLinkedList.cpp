/*
21. Merge Two Sorted Lists
Easy

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.
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

class Solution {
private:
    ListNode* head;
public:
     ~Solution()
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(!l1 && !l2)
           return nullptr;
       
       if(!l1 && l2)
           return l2;
       else if(l1 && !l2)
           return l1;
       
       ListNode* p = l1;
       ListNode* q = l2;
       ListNode* s = nullptr;
       ListNode* sortedHead = nullptr;

       while(p && q) {
           if(p->val < q->val) {
               if(!s) {
                s = p;
                sortedHead = s;
               }
               else {
                s->next = p; 
                s = s->next;  
               }
               p = p->next;
           }
           else {
               if(!s) {
                s = q;
                sortedHead = s;
               }
               else {
                s->next = q;
                s = s->next;
               }
               q = q->next;
           }
       }

       if(p) {
           s->next = p;
       }
       else if(q) {
           s->next = q;
       } 
       
        s = sortedHead;
       return s;
   }

   
};

int main() {
    Solution sol;
    ListNode* l1 = nullptr;
    l1 = sol.append(l1,1);
    l1 = sol.append(l1,3);
    l1 = sol.append(l1,5);
    
    ListNode* l2 = nullptr;
    l2 = sol.append(l2,2);
    l2 = sol.append(l2,4);
    l2 = sol.append(l2,6);

    sol.PrintSLL(l1);
    sol.PrintSLL(l2);
    auto sortedLL = sol.mergeTwoLists(l1,l2);
    sol.PrintSLL(sortedLL);

    return 0;
}