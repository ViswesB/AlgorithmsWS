/*
Implement Binary Tree
*/

#include <iostream>
using namespace std;

class BSTNode {
    public:
        BSTNode()
        {
            root = nullptr;
        }

        ~BSTNode()
        {
            //Free Memory
            destroy_bst();
        }

        void destroy_bst()
        {
            if(root != nullptr)
            {
                destroy_bst(root);
            }
        }

        void Insert(int data)
        {
            // for the first element root doesnt exist
            // So check for root being NULL before inserting.
            if(root == nullptr)
            {
                root = Allocate(data);
            }
            else {
                //If root exists then decide if data value being inserted
                //less than root->data then insert to left
                //greater than root->data then insert to right
                if(data > root->data)
                {
                    root->right = Insert(root->right,data);
                }
                else if(data < root->data)
                {
                    root->left = Insert(root->left,data);
                }
            }
        }

        BSTNode* Insert(BSTNode* node, int data)
        {
            if(node == nullptr)
            {
                node = Allocate(data);
            }
            else if(data < node->data)
            {
                node->left = Insert(node->left,data);
            }
            else if(data > node->data)
            {
                node->right = Insert(node->right,data);
            }
            return node;
        }

        void setRoot(BSTNode* node)
        {
            root = node;
        }

        BSTNode* getRoot()
        {
            return root;
        }

        //Print Elements of Binary tree in root/left/right order (preorder)
        void PrintBST()
        {
            PrintBST(root);
        }

        //Search for a element in BST
        BSTNode* Search(int value)
        {
            return Search(root,value);
        }

        //Print data from a node
        int printNode(BSTNode* node)
        {
            if(node != nullptr)
                return node->data;
        }


    private:
        int data;
        BSTNode* right;
        BSTNode* left;
        BSTNode* root;

        

        // Insert with root and data
        BSTNode* Allocate(int data)
        {
            //Allocate memory on heap
            BSTNode* node = new BSTNode();
            node->data = data;
            node->right = nullptr;
            node->left = nullptr;
            return node;
        }

        // Delete tree and free memory
        void destroy_bst(BSTNode* node)
        {
            if(node != nullptr)
            {
                destroy_bst(node->left);
                destroy_bst(node->right);
                delete node;
            }
        }

        BSTNode* Search(BSTNode* node,int value)
        {
            if(node != nullptr)
            {
                if (node->data == value)
                    return node;
                else if(value > node->data)
                    return Search(node->right,value);
                else if(value < node->data)
                    return Search(node->right,value);
                else
                    return nullptr;
            }
        }

        void PrintBST(BSTNode* node)
        {
            if(node != nullptr)
            {
                cout << node->data << "\t" ;
                PrintBST(node->left);
                PrintBST(node->right);
            }
        }
};


int main()
{
    BSTNode bst;
    // bst.setRoot(bst.Insert(bst.getRoot(),10));
    // bst.setRoot(bst.Insert(bst.getRoot(),20));
    // bst.setRoot(bst.Insert(bst.getRoot(),5));
    // bst.setRoot(bst.Insert(bst.getRoot(),35));

    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(5);
    bst.Insert(35);

    bst.PrintBST();
    cout << endl;
    BSTNode* node = bst.Search(20);
    if(node != nullptr)
    {
        cout << "Found value :" << bst.printNode(node) << endl;
    }
    node = nullptr;
    node = bst.Search(15);
    if(node != nullptr)
    {
        cout << "Found value :" << bst.printNode(node) << endl;
    }
    else {
        cout << "Value Not Found , lets Insert ??" << endl;
        bst.Insert(15);
    }

    bst.PrintBST();

    return 0;
}