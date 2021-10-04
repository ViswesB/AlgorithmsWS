/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

*/


#include <iostream>
#include <unordered_map>
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
    ListNode* curr = nullptr;
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

    // Intersection point gives only indication if cycle exists or not*/
    ListNode* intersectionPoint(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next) {
            hare = hare->next;
            tortoise = tortoise->next;
            if(hare)
                hare = hare->next;

            //Check if hare reached tortoise which indicates cycle
            if(hare == tortoise) {
                return hare;                
            }
        }
        return nullptr;
    }

    /* To detect which node is meeting tail*/
    ListNode* detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        
        if(head && !head->next)
            return nullptr;
        
        if(head && head->next) {
            if(head->next->next == head) {
                return head;
            }
        }

        auto intersection = intersectionPoint(head);
        if(!intersection)
            return nullptr;

        auto start = head;
        // // Idea is to move start and intersection point by one pointer
        // // Where start and intersection meets that is the node where tail is connecting in cycle
        while(start != intersection) {
            start = start->next;
            intersection = intersection->next;
        }

        return start;
    }
};

int main()
{
    SLL sll;
    ListNode* nodeList = nullptr;
    ListNode* newnode = new ListNode(3);
    nodeList = newnode;
    ListNode* cycnewnode = new ListNode(2);
    nodeList->next = cycnewnode;
    newnode = new ListNode(0);
    nodeList->next->next = newnode;
    newnode = new ListNode(-4);
    nodeList->next->next->next = newnode;
    nodeList->next->next->next->next = cycnewnode;

    // sll.PrintSLL(ll);

    auto retNode = sll.detectCycle(nodeList);
    if(retNode)
        cout << retNode->val << endl;
    return 0;
}