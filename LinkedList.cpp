/*
Single Linked List or Forware List
*/

#include <iostream>
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

    void PrintSLL(Node* node)
    {
        while(node!=nullptr)
        {
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
    return 0;
}