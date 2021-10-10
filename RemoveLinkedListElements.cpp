/*
203. Remove Linked List Elements
Easy

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
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

    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        
        if(head && !head->next) {
            if(head->val != val)
                return nullptr;
        }
        
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(curr) {            
            next = curr->next;
            if(curr->val == val) {
                curr->next = nullptr;
                delete curr;
                if(!prev)
                    head = next;
                else
                    prev->next = next;
            }
            else
                prev = curr;

            curr = next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* ll = nullptr;
    ll = sol.append(ll,1);
    ll = sol.append(ll,2);
    ll = sol.append(ll,6);
    ll = sol.append(ll,3);
    ll = sol.append(ll,4);
    ll = sol.append(ll,5);
    ll = sol.append(ll,6);

    sol.PrintSLL(ll);
    auto updLL = sol.removeElements(ll,6);
    sol.PrintSLL(updLL);
    return 0;
}