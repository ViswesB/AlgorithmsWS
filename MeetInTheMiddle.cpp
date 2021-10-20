/*
Meet in the middle
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

 
// Find all possible sum of elements of a[] and store
// in x[]
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll X[2000005],Y[2000005];
 
// Find all possible sum of elements of a[] and store
// in x[]
void calcsubarray(ll a[], ll x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        x[i] = s;
    }
}
 
// Returns the maximum possible sum less or equal to S
void solveSubsetSum(ll a[], int n, ll S)
{
    // Compute all subset sums of first and second
    // halves
    calcsubarray(a, X, n/2, 0);

    int xn = sizeof(X)/sizeof(X[0]);

    for(int i=0;i<xn;i++) {
        cout << X[i] << "\t";
    }

    cout << endl;

}

// Driver code
int main()
{
    ll a[] = {3, 34, 4, 12, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    ll S = 10;
    solveSubsetSum(a,n,S);
    return 0;
}