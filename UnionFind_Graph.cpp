/*
Quick Union Find 
using Graph approach where On Union (p,q) --> Parent of P will connect to Parent of Q
in this approach , we will be changing the indices of parent but not of all children or connected elements.
*/

#include<iostream>
#include<vector>
using namespace std;

class QuickUnionFindGraph {
    public:
    QuickUnionFindGraph(int N)
    {
        m_NoOfElem = N;
        /* Initialize element of array to indices/vertices*/
        for(int i=0;i<N;i++)
            vecElem.push_back(i);
    }

    /*Union(p,q) --> Parent of P will connect to Parent Q*/
    void Union(int p,int q)
    {
        //Find Parent Of P and return
        auto rootP = root(p);
        //Find Parent of Q and return
        auto rootQ = root(q);
        //Change the index of P to Index Of Q
        vecElem[rootP] = rootQ;
    }

    /*Find(p,q) --> Parent of P should be same as Parent Q*/
    bool Find(int p, int q)
    {
        return root(p) == root(q);
    }

    /*Print Elements in Graph*/
    void Print()
    {
        for(auto i:vecElem)
            cout << i << endl;
    }

    private:
    int m_NoOfElem;
    vector<int> vecElem;
    
    /* Root of P, but this is costly
        tall trees means more root calls */
    int root(int p)
    {
        int iRoot = p;
        while(vecElem[iRoot] != iRoot)
            iRoot = vecElem[iRoot];
        return iRoot;
    }
};

int main()
{
    int numOfElem = 10;
    QuickUnionFindGraph qug_(numOfElem);
    qug_.Union(4,3);
    qug_.Union(3,8);
    qug_.Union(6,5);
    qug_.Union(9,4);
    qug_.Union(2,1);
    qug_.Union(5,0);
    qug_.Union(7,2);
    qug_.Union(6,1);
    qug_.Union(7,3);
    qug_.Print();

    cout << boolalpha << qug_.Find(1,9) << endl;
    cout << boolalpha << qug_.Find(4,9) << endl;
    
    return 0;
}