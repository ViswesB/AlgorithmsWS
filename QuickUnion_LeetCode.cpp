/*
Quick Union - leetcode
this is called Quick Union as time complexity is O(n)

time complexity of Quick Union is better than Quick Find
QU - o(N)
QF - o(N2)
*/

#include <bits/stdc++.h>
using namespace std;

class quickUnion {
public:
    quickUnion(int arrSize) {
        m_vec.resize(arrSize);
        for(int i=0;i<arrSize;i++)
            m_vec[i] = i;
    }

    int find(int x) {
        while(m_vec[x] != x)
            x = m_vec[x];
        
        return x;
    }

    bool connected(int x,int y) {
        return find(x) == find(y);
    }

    void unionSet(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY)
            m_vec[rootY] = rootX;
    }
private:
    vector<int> m_vec;
};

int main() {
    unique_ptr<quickUnion> qf = make_unique<quickUnion>(7);
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