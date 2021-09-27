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
    return 0;
}