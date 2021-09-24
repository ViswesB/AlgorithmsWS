/*
Trying to understand recursion
*/
#include <iostream>
using namespace std;

int print(int n,int m) {
    if(n > 5)
        return n;

    n++;
    n = print(n);
    
    auto m = n+2;
    cout << "n:" << n << endl;
    m = print(m);
    cout << "m:" << n << endl;
    return n;
}


int main() {
    /*call print fn twice in recursion*/
    int x = 1;
    int y = 2;
    print(x,y);
    cout << " Value returned :" << y << " x returned:" << x << endl;
    return 0;
}