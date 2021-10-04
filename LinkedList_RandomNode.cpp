/*
382. Linked List Random Node
Medium

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

    Solution(ListNode head) Initializes the object with the integer array nums.
    int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.

 

Example 1:

Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

 

Constraints:

    The number of nodes in the linked list will be in the range [1, 104].
    -104 <= Node.val <= 104
    At most 104 calls will be made to getRandom.

 

Follow up:

    What if the linked list is extremely large and its length is unknown to you?
    Could you solve this efficiently without using extra space?


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
    ListNode* m_head = nullptr;
    ListNode* curr = nullptr;
public:
    void updateHead(ListNode* head) {
        m_head = head;
    }

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

    int getRandomWithoutReservoirSampling() {
        if(!m_head)
            return 0;
        curr = m_head;
        auto lenLL = len(curr);
        int randomVal = 0;
        
        int randomIndex = rand() % lenLL;
        if(!randomIndex)
            return curr->val;
        
        for(int i=1;i<=randomIndex;i++)
            curr = curr->next;
        
        return curr->val;        
    }

    int getRandom() {
        if(!m_head)
            return 0;

        // Using Reservoir Sampling
        // Idea is to use x which will be incremented till end of linked list
        // and using random we will return 
        int res = -1;
        int x = 1;
        ListNode* curr = m_head;

        while(curr) {
            int random = rand() % x; // if x is 1 then it will generate random between 0 and 1 
            // random starts with 0 while x starts at 1. hence x - 1
            if(random == x-1)
                res = curr->val;
            x += 1;
            curr = curr->next;
        }

        return res;
    }
};

int main()
{
    SLL sll;
    ListNode* ll = nullptr;
    ll = sll.append(ll,10);
    ll = sll.append(ll,1);
    ll = sll.append(ll,10);
    ll = sll.append(ll,20);
    ll = sll.append(ll,100);
    sll.updateHead(ll);
    // ll = sll.append(ll,5);
    // ll = sll.append(ll,2);

    sll.PrintSLL(ll);
    for(int i=0;i<5;i++) 
        cout << sll.getRandomWithoutReservoirSampling() << endl;
    return 0;
}