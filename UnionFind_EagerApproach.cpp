/*
Quick Union - Find - Eager Approach 
*/


#include <iostream>
#include <vector>
using namespace std;

class QuickUnionFind {
    public:
        QuickUnionFind(int N)
        {
            m_NoOfElem = N;
            //Initialize vector to 0 .. N
            for(int i=0;i<m_NoOfElem;i++)
            {
                vecInt.push_back(i);
            }
        }

        //Find Whether 2 vertices/Indexes are connected or not
        bool Find(int p,int q)
        {
            return vecInt[p] == vecInt[q];
        }

        //Connect 2 Vertices/Indexes
        void Union(int p,int q)
        {
            int valueP = vecInt[p];
            int valueQ = vecInt[q];
            for(int i=0;i<m_NoOfElem;i++)
            {
                if(vecInt[i] == valueP)
                    vecInt[i] = valueQ;
            }
        }

        //Print Contents of Vector
        void Print()
        {
            for(auto i:vecInt)
                cout << i << " " << endl;
        }
    private:
        int m_NoOfElem;
        vector<int> vecInt;
};

int main()
{
    int numOfElem = 10;
    QuickUnionFind quf_(numOfElem);
    if(!quf_.Find(4,3))
        quf_.Union(4,3);
    if(!quf_.Find(3,8))
        quf_.Union(3,8);
    quf_.Union(6,5);
    quf_.Union(9,4);
    quf_.Union(2,1);
    quf_.Union(8,9);
    quf_.Union(5,0);
    quf_.Union(7,2);
    quf_.Union(6,1);
    quf_.Print();
    return 0;
}