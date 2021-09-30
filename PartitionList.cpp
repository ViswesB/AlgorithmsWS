/*
86. Partition List
Medium

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

 

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200

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

    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        
        if(!head->next)
            return head;
        
        if(x < -200 || x > 200)
            return head;

        ListNode* curr = head;
        ListNode* lessPtr = nullptr;
        ListNode* morePtr = nullptr;
        ListNode* lessHeadPtr = nullptr;
        ListNode* moreHeadPtr = nullptr;

        while(curr) {
            if(curr->val < x) {
                cout << "less curr: " << curr->val << endl;
                if(!lessPtr) {
                    lessPtr = curr;
                    lessHeadPtr = lessPtr;
                }
                else {
                    lessPtr->next = curr;
                    lessPtr = lessPtr->next;
                }
            }
            else {
                cout << "more curr: " << curr->val << endl;
                if(!morePtr) {
                    morePtr = curr;
                    moreHeadPtr = morePtr;
                }
                else {
                    morePtr->next = curr;
                    morePtr = morePtr->next;
                }   
            }
            curr = curr->next;
        }

        if(!morePtr && !lessPtr)
            return nullptr;
        else if(!morePtr && lessPtr)
            lessPtr->next = nullptr;
        else if(morePtr && !lessPtr) {
            morePtr->next = nullptr;
            lessHeadPtr = moreHeadPtr;
        }
        else if(morePtr && lessPtr) {
            morePtr->next = nullptr;
            lessPtr->next = moreHeadPtr;
        }

        return lessHeadPtr;
    }
};

int main()
{
    SLL sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,4);
    ll = sll.append(ll,4);
    // ll = sll.append(ll,2);
    // ll = sll.append(ll,3);
    // ll = sll.append(ll,2);
    // ll = sll.append(ll,5);
    // ll = sll.append(ll,2);
    

    sll.PrintSLL(ll);
    auto partitionedLL = sll.partition(ll,8);
    if(partitionedLL)
        sll.PrintSLL(partitionedLL,true);
    return 0;
}