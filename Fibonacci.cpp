/* 
Fibonacci series
*/

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int x)
{
    if(x==0)
        return 0;
    else if(x==1)
        return 1;


    return fibonacci(x-1) + fibonacci(x-2);
}

vector<int> fibItr(int n)
{
    vector<int> fibVec;
    fibVec.push_back(0);
    fibVec.push_back(1);

    for(int i=2;i<=n;i++)
    {
        auto val = fibVec[i-1] + fibVec[i-2];
        fibVec.push_back(val);
    }
    
    return fibVec;
}

int main()
{
    int n = 38;
    auto k = fibItr(n);
    cout << "ret is: " << k[n] << endl;
    return 0;
}