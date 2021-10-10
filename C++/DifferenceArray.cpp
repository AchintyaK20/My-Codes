/*
            //Range Update Query//
An efficient solution is to use difference array.
Difference array D[i] of a given array A[i] is defined as 
D[i] = A[i]-A[i-1] (for 0 < i < N ) and D[0] = A[0] 
considering 0 based indexing. 
Difference array can be used to perform range update 
queries "l r x" where l is left index, r is right index 
and x is value to be added and after all queries you can 
return original array from it. Where update range operations 
can be performed in O(1) complexity.

1. update(l, r, x) : Add x to D[l] and subtract it from D[r+1], i.e., we do D[l] += x, D[r+1] -= x
2. printArray() : Do A[0] = D[0] and print it. For rest of the elements, do A[i] = A[i-1] + D[i] and print them.
Time complexity of update here is improved to O(1). Note that printArray() still takes O(n) time.

*/
#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl "\n"
#define CEIL(a,b) ceil((float)(a)/(b))
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

vector<int> initializeDiffArray(vector<int>& A)
{
    int n = sz(A);

    // We use one extra space because
    // update(l, r, x) updates D[r+1]
    vector<int> D(n + 1);

    D[0] = A[0], D[n] = 0;
    for (int i = 1; i < n; i++)
    {
        D[i] = A[i] - A[i - 1];
    }
    return D;
}

// Does range update
void update(vector<int>& D, int l, int r, int x)
{
    D[l] = D[l] + x;
    D[r + 1] = D[r + 1] - x;
}

// Prints updated Array
void printArray(vector<int>& A, vector<int>& D)
{
    for (int i = 0; i < sz(A); i++)
    {
        if (i == 0)
        {
            A[i] = D[i];
        }
        // Note that A[0] or D[0] decides
        // values of rest of the elements.
        else
        {
            A[i] = D[i] + A[i - 1];
        }
        cout << A[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Array to be updated
    vector<int> A{ 10, 5, 20, 40 };

    // Create and fill difference Array
    vector<int> D = initializeDiffArray(A);

    // After below update(l, r, x), the
    // elements should become 20, 15, 20, 40
    update(D, 0, 1, 10);
    printArray(A, D);

    // After below updates, the
    // array should become 30, 35, 70, 60
    update(D, 1, 3, 20);
    update(D, 2, 2, 30);
    printArray(A, D);

    return 0;
}
