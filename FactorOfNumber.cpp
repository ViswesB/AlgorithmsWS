/*
Factor of a number
*/

#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    set<int> factor(int n) {
        set<int> factorList;
        factorList.insert(1);
        for(int i=2;i<=n;i++) {
            if(n%i == 0) {
                auto ret = factorList.insert(i);
                if(ret.second == false)
                    break;
            }
        }

        return factorList;
    }
};

int main() {
    shared_ptr<Solution> sol = make_shared<Solution>();
    int n = 3072;
    auto factorList = sol->factor(n);
    for(auto itr:factorList)
        cout << itr << "\t"; 
    cout << endl;
    return 0;
}
