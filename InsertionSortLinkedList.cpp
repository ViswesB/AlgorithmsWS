/*
147. Insertion Sort List
Medium

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

    Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
    It repeats until no input elements remain.

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

 

Constraints:

    The number of nodes in the list is in the range [1, 5000].
    -5000 <= Node.val <= 5000

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

    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* unsortedLL = head;
        ListNode* sortedLL = new ListNode(unsortedLL->val);
        ListNode* headSortedLL = sortedLL;

        while(unsortedLL->next) {
            unsortedLL = unsortedLL->next;
            cout << unsortedLL->val << endl;
            while(sortedLL) {
                auto newNode = new ListNode(unsortedLL->val);
                if(unsortedLL->val < sortedLL->val) {
                    cout << unsortedLL->val << "\t" << sortedLL->val << endl;
                    auto tmpHead = headSortedLL;
                    newNode->next = tmpHead;
                    headSortedLL = newNode;
                }
                else {
                    // PrintSLL(sortedLL);
                    // if(!sortedLL->next) {
                    //     cout << "6 should have been updated here" << endl;
                    //     sortedLL->next = newNode;
                    // }
                }
                sortedLL = sortedLL->next;
                if(!sortedLL)
                    cout << "next element of sorted LL is null" << endl;
                else 
                    cout << "really ?? what value: " << sortedLL->val << endl;
            }
            cout << "out of sorted loop" << endl;
            sortedLL = headSortedLL;
            
        }
        return headSortedLL;
    }
};

int main()
{
    SLL sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,4);
    ll = sll.append(ll,2);
    ll = sll.append(ll,1);
    ll = sll.append(ll,6);
    // ll = sll.append(ll,0);
    // ll = sll.append(ll,3);
    // ll = sll.append(ll,5);
    // ll = sll.append(ll,2);

    sll.PrintSLL(ll);
    auto sortedLL = sll.insertionSortList(ll);
    sll.PrintSLL(sortedLL);
    return 0;
}