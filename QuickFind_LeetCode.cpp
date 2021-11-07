/*
Quick Find - Leetcode 
this is called quick find as find has better time complexity
*/

#include <bits/stdc++.h>
using namespace std;

class quickFind {
public:
    quickFind(int arrSize) {
        m_vec.resize(arrSize);
        for(int i=0;i<arrSize;i++)
           m_vec[i] = i;
    }

    //find parent or root node of x
    //O(1)
    int find(int x) {
        return m_vec[x];
    }

    bool connected(int x,int y) {
        return find(x) == find(y);
    }

    //connecting 2 nodes x and y
    //while connecting we are modifying parent of y connected nodes
    //O(N 2 (square))
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            //find rootY in vec and replace with new root X
            for(int i=0;i<m_vec.size();i++) {
                if(m_vec[i] == rootY)
                    m_vec[i] = rootX;
            }
        }
    }

private:
    vector<int> m_vec;
};

int main() {
    unique_ptr<quickFind> qf = make_unique<quickFind>(7);
    cout << boolalpha << endl;
    qf->unionSet(1,3);
    qf->unionSet(1,4);
    cout << qf->connected(1,3) << endl;
    cout << qf->connected(1,4) << endl;

    qf->unionSet(2,5);
    qf->unionSet(2,6);
    cout << qf->connected(2,5) << endl;
    cout << qf->connected(2,6) << endl;

    qf->unionSet(0,1);
    cout << qf->connected(0,3) << endl;
    cout << qf->connected(0,4) << endl;
    cout << qf->connected(0,2) << endl;
    return 0;
}