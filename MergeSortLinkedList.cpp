/*
148. Sort List
Medium

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105
*/

#include <iostream>
using namespace std;

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

    //using mergesort
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }

    void getMIDandUPPERNode(ListNode* head, ListNode** leftNode, ListNode** midNode, ListNode** rightNode) {
        while((*rightNode) && (*rightNode)->next) {
            *leftNode = *midNode;
            *rightNode = (*rightNode)->next;
            *midNode = (*midNode)->next;
            if((*rightNode)->next) {
                *rightNode = (*rightNode)->next;
            }
        }
    }

    void mergeSort(ListNode** headNode) {
        ListNode* curr = *headNode;
        PrintSLL(*headNode);
        if(!curr)
            return;

        if(curr && !curr->next) {
            return;
        }

         // Find mid node / end 
        ListNode* rightNode = curr;
        ListNode* leftNode = curr;
        ListNode* midNode = curr;

        getMIDandUPPERNode(curr,&leftNode,&midNode,&rightNode);
        leftNode->next = nullptr;
        mergeSort(&curr);
        mergeSort(&midNode);
        *headNode = merge(curr,midNode);
        cout << "After merge" << endl;
        PrintSLL(*headNode);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = nullptr;
        if(!left)
            return right;
        
        if(!right)
            return left;

        if(!left && !right)
            return nullptr;

        cout << "left is: " << endl;
        PrintSLL(left);
        cout << "right is: " << endl;
        PrintSLL(right);
        if(left->val<right->val){
            head=left;
            head->next=merge(left->next,right);
        }
        else{
            head=right;
            head->next=merge(left,right->next);
        }
        cout << "returning" << endl;
        PrintSLL(head);
        return head;
    }
};

int main()
{
    SLL sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,4);
    ll = sll.append(ll,3);
    ll = sll.append(ll,2);
    ll = sll.append(ll,1);
    // ll = sll.append(ll,8);
    // ll = sll.append(ll,7);
    // ll = sll.append(ll,6);
    // ll = sll.append(ll,5);

    sll.PrintSLL(ll,true);
    auto sortedLL = sll.sortList(ll);
    cout << "SORTED LIST IS:" << endl;
    sll.PrintSLL(sortedLL);
    return 0;
}