/*
push elements of array into stack , and pop on reading -
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    int n = 5;
    for(auto i=1;i<=n;i++)
    {
        stk.push(i);
        stk.push(0);
    }

    cout << stk.size() << endl;

    while(!stk.empty())
    {
        // cout << stk.top() << "\t";
        auto i = stk.top();
        if(i != 0){
            cout << i << "\t";
        }
        stk.pop();
    }
    cout << endl;
    return 0;
}