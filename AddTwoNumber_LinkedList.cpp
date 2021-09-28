/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= ListNode*.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

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

    /* Add numbers from LinkedList */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return nullptr;

        if(!l1)
            return l2;
        
        if(!l2)
            return l1;

        ListNode* currA = l1;
        ListNode* currB = l2;
        ListNode* node = nullptr;
        ListNode* sumHead = nullptr;
        ListNode* sumNode = sumHead;
        int carryForward = 0;
        int sum = 0;

        // List contains single element
        if(!l1->next && !l2->next) {
            sum = l1->val + l2->val;
            auto sumToInsert = 0;
            if(sum >= 10) {
                carryForward = 1;
                sumToInsert = sum - 10;
            }
            else {
                carryForward = 0;
                sumToInsert = sum;
            }
            sumHead = append(sumHead,sumToInsert);
            if(carryForward)
                sumHead = append(sumHead,carryForward);
            return sumHead;
        }


        //which among the 2 lists are bigger
        auto lenA = len(currA);
        auto lenB = len(currB);
        currA = l1;
        currB = l2;

        if(lenA > lenB)
            node = currA;
        else
            node = currB;
        
        while(node) {
            int sumA = 0, sumB = 0;
            if(currA) {
                sumA = currA->val;
                currA = currA->next;
            }
            if(currB) {
                sumB = currB->val;
                currB = currB->next;
            }
            sum = sumA + sumB + carryForward;
            auto sumToInsert = 0;
            if(sum >= 10) {
                carryForward = 1;
                sumToInsert = sum - 10;
            }
            else {
                carryForward = 0;
                sumToInsert = sum;
            }
            sumHead = append(sumHead,sumToInsert);
            node = node->next;
        }

        if(carryForward)
            sumHead = append(sumHead,carryForward);
        return sumHead;
    }
};

int main()
{
    SLL sLinkedList;
    ListNode* listA = nullptr;
    ListNode* listB = nullptr;
    
    // listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);
    listA = sLinkedList.append(listA,9);

    listB = sLinkedList.append(listB,9);
    listB = sLinkedList.append(listB,9);
    listB = sLinkedList.append(listB,9);
    listB = sLinkedList.append(listB,9);
    

    sLinkedList.PrintSLL(listA);
    sLinkedList.PrintSLL(listB);

    cout << "Add Two Numbers" << endl;
    auto TwoNumb = sLinkedList.addTwoNumbers(listA,listB);
    if(TwoNumb)
        sLinkedList.PrintSLL(TwoNumb);
    return 0;
}