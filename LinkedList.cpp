/*
Single Linked List or Forware List
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node():val(0),next(nullptr){}
    Node(int x):val(x), next(nullptr){}
    Node(int x,Node* nxt):val(x), next(nxt){}
};

class SLL {
private:
    Node* head = nullptr;
    size_t m_SLLSize = 0;
public:
    ~SLL()
    {
        // destroySLL();
    }
    Node* returnHead()
    {
        return head;
    }

    void InsertAtFront(int x)
    {
        Node* node = nullptr;
        node = new Node(x);
        Node* tmpHead = head;
        node->next = tmpHead;
        head = node;
        m_SLLSize++;
    }
    
    void InsertAtEnd(int x)
    {
        Node* node = nullptr;
        node = new Node(x);
        // head is null which means we have created first element
        if(!head) {
            head = node;
        }
        else {
            Node* tmpNode = head;
            //Moving pointer to end of list
            while(tmpNode->next){ 
                tmpNode = tmpNode->next;
            }
            tmpNode->next = node;
        }
        m_SLLSize++;
    }

    Node* append(Node* head,int x)
    {
        //remembering last address
        Node* last = head;
        Node* node = new Node(x);
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

    // Assuming position of head is 0, idea is to insert at that position
    void InsertAfterNode(Node* prev, int x)
    {
        Node* tmpHead = head;
        Node* newNode = new Node(x);
        newNode->next = prev->next;
        prev->next = newNode;
        m_SLLSize++;
    }

    size_t size()
    {
        return m_SLLSize;
    }

    void destroySLL()
    {
        Node* node = head;
        while(!node)
        {
            delete node->next;
            delete node;
        }
    }

    void displayList()
    {
        Node* pnode = head;
        while (pnode != nullptr)
        {
            cout << pnode->val  << "-->";
            pnode = pnode->next;
        }
        if(pnode == nullptr)
            cout << "NULL" << endl;
    }

    void PrintSLL(Node* node, bool addAddress=false)
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

    void reverseSLL()
    {
        //Curr will keep moving node and de-linking
        //prev will keep building new links in reverse order
        Node* curr = head;
        Node* prev = nullptr;
        while(curr)
        {
            Node* tempNode = curr->next;
            //there's only one element in LL
            if(!prev && !tempNode)
                break;

            if(!prev)
            {
                //dealing with first element of LL
                curr->next = nullptr;
            }
            else {
                //moving on to other elements of LL
                curr->next = prev;
            }
            prev = curr;
            curr = tempNode;
        }
        head = prev;
    }

    // remove node from list matching value of val
    void remove(int val)
    {
        Node* temp = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while(temp != nullptr)
        {
            if(temp->val == val)
            {
                //Found node matching val
                if(!prev) {
                    next = temp->next;
                    temp->next = nullptr;
                    delete temp;
                    head = next;
                    temp = head;
                }
                else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev;
                }
                m_SLLSize--;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    /* l1 and l2 are both sorted */
    Node* mergeTwoLists(Node* l1, Node* l2)
    {
        if(!l1 && !l2)
            return l1;
        
        if(!l1 || !l2)
        {
            //one of the list is empty check which list and return other list
            if(l1)
                return l1;
            else if(l2)
                return l2;
        }

        //remember head of l2
        Node* headL2 = l2;
        Node* headL1 = l1;
        Node* newSortedLL = nullptr;
        Node* headNewSortedLL = nullptr;

        while(headL1 && headL2)
        {
           if(headL1->val <= headL2->val)
           {
               if(!newSortedLL) {
                    newSortedLL = headL1;
                    headNewSortedLL = newSortedLL;
               }
               else {
                    newSortedLL->next = headL1;
                    newSortedLL = newSortedLL->next;
               }
               headL1 = headL1->next;
           }
           else {
               if(!newSortedLL) {
                   newSortedLL = headL2;
                   headNewSortedLL = newSortedLL;
               }
               else {
                   newSortedLL->next = headL2;
                   newSortedLL = newSortedLL->next;
               }
               headL2 = headL2->next;
           }
        }

        if(!headL1) {
            newSortedLL->next = headL2;
        }
        else {
            newSortedLL->next = headL1;
        }

        newSortedLL = headNewSortedLL;
        return newSortedLL;
    }

    Node* deleteDuplicates(Node* head) {
        Node* curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        bool isHeadNodeUpdated = false;
        if(!head)
            return head;

        while(curr) {
            isHeadNodeUpdated = false; // reset
            // this is sorted linked list
            // compare curr element and its next element
            // if same then de-link/delete/re-link
            
            if(curr->next) {
                if(curr->val == curr->next->val) {
                    // delete current element
                    if(!prev) {
                        next = curr->next;
                        curr->next = nullptr;
                        delete curr;
                        curr = next;
                        head = curr;
                        prev = nullptr;
                        isHeadNodeUpdated = true;
                    }
                    else {
                        next = curr->next;
                        prev->next = next;
                        curr->next = nullptr;
                        delete curr;
                        curr = prev;
                    }
                }
                else {
                    if((prev) && (prev->val == curr->val)) {
                        //delete curr
                        prev->next = nullptr;
                        delete curr;
                        curr = nullptr;
                        curr = prev;
                    }
                    prev = curr;
                }
            }
            else {
                // previous and current can be same value while curr->next is null
                if((prev) && (prev->val == curr->val)) {
                    //delete curr
                    prev->next = nullptr;
                    delete curr;
                    curr = nullptr;
                    curr = prev;
                }
            }
            if(!isHeadNodeUpdated)
                curr = curr->next;
        }

        return head;
    }

    bool hasCycle(Node* head) {
        if(!head)
            return false;
        
        if(!head->next)
            return false;

        Node* node = head;
        bool isCycle = false;

        unordered_set<Node*> uoNodePtr;
        while(node) {
            auto retPair = uoNodePtr.insert(node->next);
            if(retPair.second) {
                cout << "Inserted elem: " << node->val << endl;
            }
            else {
                cout << "Element: " << node->next->val << " already exits in unordered set" << endl;
                isCycle = true;
                // Breaking as tail isnt pointing to null for while loop to end
                break;
            }
            node = node->next;
        }
        return isCycle;
    }

    Node* getIntersectionNode(Node* headA, Node* headB) {
        Node* intersectedNode = nullptr;
        if(!headA->next && !headB->next) {
            if(headA == headB) {
                cout << headA << " ---- " << headB << endl;
                intersectedNode = headA;
            }
            return intersectedNode;
        }
            
        // Idea is to merge ListA and ListB (not sorted)
        // If there is intersection then we have cycle linked list
        // else we would reach end of list which means no intersection
        Node* hA = headA;
        Node* hB = headB;
        unordered_set<Node*> uoNodeNext;
        // moving headA to last element
        while(hA) {
            uoNodeNext.insert(hA);
            hA = hA->next;
        }

        //hA should be single linked list // WE ARE MODIFYING listA
        hA = hB;

        cout << "hA->val: "  << hA->val << " " << hA->next->val << endl;

        while(hB) {
            cout << "hB->val: " << hB->val << "  " << hB << endl;
            auto retPair = uoNodeNext.insert(hB);
            if(!retPair.second) {
                cout << "Cycle Linked List exists at: " << hB->next->val << endl;
                intersectedNode = hB;
                break;
            }
            hB = hB->next;
        }

        return intersectedNode;
    }

    /* Returns length of Linked List */
    int len(Node* node) {
        int count = 0;
        while(node) {
            count++;
            node = node->next;
        }
        return count;
    }

    Node* getIntersectionNodeByCount(Node* headA, Node* headB) {
        Node* intersectedNode = nullptr;

        if(!headA->next && !headB->next) {
            if(headA == headB) {
                cout << headA << " ---- " << headB << endl;
                intersectedNode = headA;
            }
            return intersectedNode;
        }
            
        // Idea is to merge ListA and ListB (not sorted)
        // If there is intersection then we have cycle linked list
        // else we would reach end of list which means no intersection
        Node* hA = headA;
        Node* hB = headB;

        // Get Length of ListA
        auto lenA = len(hA);
        // Get Length of ListB
        auto lenB = len(hB);
        
        // Idea is to find difference among two lists say K
        // Move Bigger among two lists by K elements
        if(lenA >= lenB) {
            auto k = lenA - lenB;
            // Move ListA by k
            for(int i=0;i<k;i++) {
                if(hA)
                    hA = hA->next;
            }
        }
        else {
            auto k = lenB - lenA;
            //Move ListB by k
            for(int i=0;i<k;i++) {
                if(hB)
                    hB = hB->next;
            }
        }

        //Now compare hA with hB for finding intersection
        while(hA && hB) {
            if(hA == hB) {
                //Found intersection point;
                intersectedNode = hA;
                break;
            }
            hA = hA->next;
            hB = hB->next;
        }

        return intersectedNode;
    }

    Node* removeElements(Node* head, int val) {
        if(!head)
            return head;

        Node* curr = head;
        Node* prev = nullptr;

        while(curr) {
            if(curr->val == val) {
                //check if element found is at head
                if(!prev) {
                    prev = nullptr;
                    auto next = curr->next;
                    delete curr;
                    curr = next;
                    head = curr;
                }
                else {
                    if(!curr->next)
                        prev->next = nullptr;
                    else
                        prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

    Node* reverseList(Node* head) {
        if(!head)
            return head;
        
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node* tempNode = nullptr;

        while(curr) {
            next = curr->next;
            if(!prev) {
                prev = curr;
                prev->next = nullptr;
            }
            else {
                tempNode = prev;
                prev = curr;
                prev->next = tempNode;
            }
            curr = next;
        }

        head = prev;
        return head;
    }

    bool isPalindrome(Node* head) {
        bool isLLPalindrome = false;
        if(!head)
            return isLLPalindrome;

        if(!head->next)
            return isLLPalindrome;

        // Idea is to use "Floyd's Cycle detection" to use slow and fast pointers
        // when fast reaches null or fast->next reaches null then slow pointer should be at middle node
        Node* slow = head;
        Node* fast = head;

        while(slow && fast) {
            slow = slow->next;
            // Moving fast by 2 elements
            fast = fast->next;
            if(fast && fast->next)
                fast = fast->next;
            else
                break;
        }
        
        //slow should be pointing to middle element
        //fast or fast->next should be pointing to null 

        // Reverse list from slow to end of List
        Node* prev = nullptr;
        Node* next = nullptr;
        while(slow) {
            next = slow->next;
            slow->next = prev; 
            prev = slow;
            slow = next;
        }
        slow = prev;
        PrintSLL(slow);

        // // re-direct fast to head
        fast = head;
        while(slow && fast) {
            if(slow->val == fast->val) {
                isLLPalindrome = true;
                slow = slow->next;
                fast = fast->next;
            }
            else {
                isLLPalindrome = false;
                break;
            }
        }

        return isLLPalindrome;
    }

    // Delete a node without head or prev pointers
    void deleteNode(Node* node) {
        if(!node)
            return;
        
        // only one element remains i.e. tail
        if(!node->next) {
            return;
        }

        // Idea is to use next element i.e. 
        // keep address of deleted node and 
        // copy value of next element in deleted node
        // change deleted node -> next to next of next

        Node* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }

    Node* middleNode(Node* head) {
        if(!head)
            return head;

        if(!head->next)
            return head;

        //slow and fast pointers "Floyds Cyclic Detection"
        // by the time fast pointer or fast->next reaches null
        // slow would be at middle node
        Node* slow = head;
        Node* fast = head;
        while(slow && fast) {
            if(fast->next)
                fast = fast->next;
            else
                break;
            
            slow = slow->next;

            if(fast && fast->next)
                fast = fast->next;
            else
                break;
            
        }
        return slow;
    }

    /*
    1290. Convert Binary Number in a Linked List to Integer

    Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

    Return the decimal value of the number in the linked list.

    

    Example 1:

    Input: head = [1,0,1]
    Output: 5
    Explanation: (101) in base 2 = (5) in base 10

    Example 2:

    Input: head = [0]
    Output: 0

    Example 3:

    Input: head = [1]
    Output: 1

    Example 4:

    Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
    Output: 18880

    Example 5:

    Input: head = [0,0]
    Output: 0
*/
    int getDecimalValue(Node* head) {
        if(!head) 
            return 0;   
        
        if(!head->next)
            return head->val;

        int sum = 0;
        int leftShiftCounter = 0;
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        // Idea is to reverse linked list
        // then left shift head->val by leftShiftCounter
        // and add to sum
        while(curr) {
            //reverse linkedlist
            next = curr->next;
            curr->next = prev; //de-linked
            prev = curr;
            curr = next;
        }
        PrintSLL(prev);

        while(prev) {
            auto nodeValue = prev->val << leftShiftCounter;
            sum += nodeValue;
            leftShiftCounter++;
            prev = prev->next;
        }

        return sum;
    }
};

int main()
{
    SLL sLinkedList;
    sLinkedList.InsertAtEnd(16);
    sLinkedList.InsertAtEnd(10);
    sLinkedList.InsertAtEnd(5);
    sLinkedList.InsertAtEnd(9);
    sLinkedList.InsertAtFront(2);
    sLinkedList.InsertAfterNode(sLinkedList.returnHead()->next->next->next,100);
    sLinkedList.InsertAtEnd(700);
    sLinkedList.InsertAtEnd(701);
    sLinkedList.InsertAtEnd(9);
    sLinkedList.InsertAtEnd(800);
    sLinkedList.InsertAtEnd(801);
    sLinkedList.InsertAtEnd(2);
    sLinkedList.PrintSLL(sLinkedList.returnHead());
    sLinkedList.remove(9);
    sLinkedList.remove(2);
    sLinkedList.PrintSLL(sLinkedList.returnHead());
    sLinkedList.reverseSLL();
    sLinkedList.PrintSLL(sLinkedList.returnHead());
    sLinkedList.reverseSLL();
    sLinkedList.PrintSLL(sLinkedList.returnHead());
    cout << "size is: " << sLinkedList.size() <<endl;

    // create l1 and l2
    Node* l1 = nullptr;
    l1 = sLinkedList.append(l1,7);
    l1 = sLinkedList.append(l1,8);
    l1 = sLinkedList.append(l1,9);
    sLinkedList.PrintSLL(l1);

    // create l2
    Node* l2 = nullptr;
    l2 = sLinkedList.append(l2,2);
    l2 = sLinkedList.append(l2,4);
    l2 = sLinkedList.append(l2,6);
    sLinkedList.PrintSLL(l2);

    auto mergedList = sLinkedList.mergeTwoLists(l1,l2);
    if(!mergedList)
        cout << "Merged List is empty" << endl;
    else {
        cout << "----------- Printing merged list ----------------" << endl;
        sLinkedList.PrintSLL(mergedList);
    }

    // Delete Duplicates from a sorted linked list
    Node* sortedList = nullptr;
    sortedList = sLinkedList.append(sortedList,1);
    sortedList = sLinkedList.append(sortedList,1);
    sortedList = sLinkedList.append(sortedList,1);
    sortedList = sLinkedList.append(sortedList,1);
    sortedList = sLinkedList.append(sortedList,3);
    sortedList = sLinkedList.append(sortedList,3);
    sortedList = sLinkedList.append(sortedList,3);
    sortedList = sLinkedList.append(sortedList,3);
    sortedList = sLinkedList.append(sortedList,4);
    sortedList = sLinkedList.append(sortedList,4);
    sortedList = sLinkedList.append(sortedList,5);
    sortedList = sLinkedList.append(sortedList,5);
    sortedList = sLinkedList.append(sortedList,5);
    sortedList = sLinkedList.append(sortedList,5);
    
    cout << "----------- Printing Sorted list ----------------" << endl;
    sLinkedList.PrintSLL(sortedList);
    auto sortedUniqueList = sLinkedList.deleteDuplicates(sortedList);
    sLinkedList.PrintSLL(sortedUniqueList);

    // trying to tamper sortedUniqueList
    // Node* cycleElem = sortedUniqueList->next;
    // sortedUniqueList->next->next->next->next = cycleElem;
    Node* cycleElem = nullptr;
    cycleElem = sLinkedList.append(cycleElem,1);
    cycleElem = sLinkedList.append(cycleElem,2);
    Node* cycleHead = cycleElem;
    cycleElem->next->next = cycleHead;
    cout << boolalpha << "is this LL cycle: " << sLinkedList.hasCycle(cycleElem) << endl;
    

//    Building 2 nodes
    Node* nodeOne = nullptr;
    Node* intersectionNode = new Node(4);
    Node* nodeTwo = nullptr;
    nodeOne = intersectionNode;
    // nodeTwo = intersectionNode; //del
    intersectionNode = new Node(1);
    nodeOne->next = intersectionNode;
    // nodeTwo->next = intersectionNode; //del

    
    intersectionNode = new Node(5);
    nodeTwo = intersectionNode;
    intersectionNode = new Node(6);
    nodeTwo->next = intersectionNode;
    intersectionNode = new Node(1);
    nodeTwo->next->next = intersectionNode;
    
    intersectionNode = new Node(8);
    nodeOne->next->next = intersectionNode;
    // nodeTwo->next->next = intersectionNode; //del
    nodeTwo->next->next->next = intersectionNode;
    intersectionNode = new Node(4);
    nodeOne->next->next->next = intersectionNode;
    // nodeTwo->next->next->next = intersectionNode; //del
    nodeTwo->next->next->next->next = intersectionNode;
    intersectionNode = new Node(5);
    nodeOne->next->next->next->next = intersectionNode;
    // nodeTwo->next->next->next->next = intersectionNode; //del
    nodeTwo->next->next->next->next->next = intersectionNode;

    nodeOne->next->next->next->next->next = nullptr;
    nodeTwo->next->next->next->next->next->next = nullptr;
    // nodeTwo->next->next->next->next->next = nullptr; //del

    // Node* nodeOne = nullptr;
    // Node* intersectionNode = new Node(1);
    // Node* nodeTwo = nullptr;
    // nodeOne = intersectionNode;
    // intersectionNode = new Node(2);
    // nodeTwo = intersectionNode;

    cout << "----------- Printing Manual Linked list ----------------" << endl;
    intersectionNode = nullptr;
    sLinkedList.PrintSLL(nodeOne,true);
    sLinkedList.PrintSLL(nodeTwo,true);
    
    intersectionNode = sLinkedList.getIntersectionNodeByCount(nodeOne,nodeTwo);
    if(intersectionNode)
        cout << "Intersected Node: " << intersectionNode->val << endl;
    else
        cout << "No Intersection" << endl;

    // Delete elements from a linked list matching val
    Node* newLL = nullptr;
    newLL = sLinkedList.append(newLL,7);
    newLL = sLinkedList.append(newLL,7);
    newLL = sLinkedList.append(newLL,7);
    newLL = sLinkedList.append(newLL,7);
    newLL = sLinkedList.append(newLL,3);
    // newLL = sLinkedList.append(newLL,4);
    // newLL = sLinkedList.append(newLL,5);
    // newLL = sLinkedList.append(newLL,6);

    cout << "----------- Printing Linked list ----------------" << endl;
    sLinkedList.PrintSLL(newLL);
    int valToDelete = 7;
    cout << "----- REMOVING ELEMENTS ----- : " << valToDelete << endl;
    auto afterDelLL = sLinkedList.removeElements(newLL,valToDelete);
    sLinkedList.PrintSLL(afterDelLL);


    // Print linked list in reverse
    cout << "----------- Printing Linked list in REVERSE ----------------" << endl;
    Node* reverseList = nullptr;
    reverseList = sLinkedList.append(reverseList,1);
    reverseList = sLinkedList.append(reverseList,2);
    reverseList = sLinkedList.append(reverseList,3);
    reverseList = sLinkedList.append(reverseList,4);
    reverseList = sLinkedList.append(reverseList,5);
    reverseList = sLinkedList.append(reverseList,6);
    reverseList = sLinkedList.append(reverseList,7);
    reverseList = sLinkedList.append(reverseList,8);
    sLinkedList.PrintSLL(reverseList);
    sLinkedList.PrintSLL(sLinkedList.reverseList(reverseList));

    // Palindrome or not
    cout << "----------- Printing Linked list for Palindrome ----------------" << endl;
    Node* palindromeList = nullptr;
    //100
    palindromeList = sLinkedList.append(palindromeList,1);
    palindromeList = sLinkedList.append(palindromeList,0);
    palindromeList = sLinkedList.append(palindromeList,0);
    //906609
    // palindromeList = sLinkedList.append(palindromeList,9);
    // palindromeList = sLinkedList.append(palindromeList,0);
    // palindromeList = sLinkedList.append(palindromeList,6);
    // palindromeList = sLinkedList.append(palindromeList,6);
    // palindromeList = sLinkedList.append(palindromeList,0);
    // palindromeList = sLinkedList.append(palindromeList,9);
    
    sLinkedList.PrintSLL(palindromeList);
    cout << boolalpha << "is this Palindrome??: " << sLinkedList.isPalindrome(palindromeList) << endl;

    // delete a node with head or prev element of linkedlist
    cout << "----------- Printing Linked list for Deletion of node without head ----------------" << endl;
    //1->2->3->4->5->6->7->null
    Node* nodeList = nullptr;
    Node* newnode = new Node(1);
    nodeList = newnode;
    newnode = new Node(2);
    nodeList->next = newnode;
    newnode = new Node(3);
    nodeList->next->next = newnode;
    newnode = new Node(4);
    nodeList->next->next->next = newnode;
    newnode = new Node(5);
    nodeList->next->next->next->next = newnode;
    Node* deletedNode = newnode;
    newnode = new Node(6);
    nodeList->next->next->next->next->next = newnode;
    newnode = new Node(7);
    nodeList->next->next->next->next->next->next = newnode;

    nodeList->next->next->next->next->next->next->next = nullptr;

    sLinkedList.PrintSLL(nodeList);
    sLinkedList.deleteNode(deletedNode);
    cout << "----------- Printing Linked list After Deletion of node without head ----------------" << endl;
    sLinkedList.PrintSLL(nodeList);


    cout << "For Middle Node of Linked List" << endl;
    Node* ll = nullptr;
    // ll = sLinkedList.append(ll,1);
    // ll = sLinkedList.append(ll,2);
    // ll = sLinkedList.append(ll,3);
    // ll = sLinkedList.append(ll,4);
    // ll = sLinkedList.append(ll,5);
    // ll = sLinkedList.append(ll,6);
    sLinkedList.PrintSLL(ll);
    auto middleNode = sLinkedList.middleNode(ll);
    if(middleNode)
        cout << "middleNode is: " << middleNode->val << endl;

    cout << "For decimal value from Linked list of binary digits " << endl;
    Node* binaryLL = nullptr;
    // [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
    binaryLL = sLinkedList.append(binaryLL,1);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,1);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,1);
    binaryLL = sLinkedList.append(binaryLL,1);
    binaryLL = sLinkedList.append(binaryLL,1);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    binaryLL = sLinkedList.append(binaryLL,0);
    

    sLinkedList.PrintSLL(binaryLL);
    cout << "Decimal value from Binary Linked List:" << sLinkedList.getDecimalValue(binaryLL) << endl;

    return 0;
}