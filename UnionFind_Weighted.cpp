/*
Weighted Quick Union Find

a. avoid tall trees
b. Connect or Union by connecting root of smaller tree to root of larger tree (always smaller tree lower)
c. need to maintain tree size aka elements of tree
*/

#include <iostream>
#include <vector>
using namespace std;

const int ELEM_VECTOR = 1;
const int SZE_VECTOR = 0;

class WeightedQuickUnionFind
{
    public:

    WeightedQuickUnionFind(int N,bool isPathCompressionEnabled=false)
    {
        m_NoOfElem = N;
        m_isPathCompressionEnabled = isPathCompressionEnabled;
        //Initialize
        for (int i=0;i<m_NoOfElem;i++) {
            vecElem.push_back(i);
            vecSze.push_back(1);
        }
    }

    /* Find(p,q) --> Root of P should be connected to Root of Q*/
    bool Find(int p,int q)
    {
        return root(p) == root(q);
    }

    /* Union of p and q will be based on size. 
    parent/root of p will be connected to parent of q if size of parent of q is smaller 
    i.e. smaller tree will be child of larger parent */
    void Union(int p,int q)
    {
        auto indexI = root(p);
        auto indexJ = root(q);
        if(vecSze[indexI] >= vecSze[indexJ]){
            vecElem[indexJ] = vecElem[indexI];
            vecSze[indexI] += vecSze[indexJ];
        }
        else {
            vecElem[indexI] = vecElem[indexJ];
            vecSze[indexJ] += vecSze[indexI];
        }
    }

    void Print(int choosenVec)
    {
        vector<int> vec;
        if(choosenVec)
            vec = vecElem;
        else
            vec = vecSze;

        for(auto i:vec)
            cout << i << "\t" ;
        cout << endl;
    }

    private:

    int m_NoOfElem;
    bool m_isPathCompressionEnabled;
    vector<int> vecElem;
    vector<int> vecSze;

    /* Root of element should be parent until root of the element is same as itself*/
    int root(int p)
    {
        int rootElem = p;
        while(vecElem[rootElem] != rootElem) {
            rootElem = vecElem[rootElem];
            if(m_isPathCompressionEnabled)
                vecElem[rootElem] = vecElem[vecElem[rootElem]];
        }
        return rootElem;
    }
};

int main()
{
    int noElem = 10;
    WeightedQuickUnionFind wqf(10,true);
    wqf.Union(4,3);
    wqf.Union(3,8);
    wqf.Union(6,5);
    wqf.Union(9,4);
    wqf.Union(2,1);
    wqf.Union(5,0);
    wqf.Union(7,2);
    wqf.Union(6,1);
    cout << boolalpha << "Find(3,1): " << wqf.Find(3,1)  << endl;
    wqf.Union(7,3);
    wqf.Print(ELEM_VECTOR);

    cout << boolalpha << "Find(3,1): " << wqf.Find(3,1)  << endl;
    cout << boolalpha << "Find(4,0): " << wqf.Find(4,0)  << endl;
    return 0;
}