// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

long long dp[101][101];
long long game(int a[], int i, int j)
{
    if (i + 1 == j)
    {
        return max(a[i], a[j]);
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(a[i] + min(game(a, i + 2, j), game(a, i + 1, j - 1)),
                          a[j] + min(game(a, i, j - 2), game(a, i + 1, j - 1)));
}

long long maximumAmount(int arr[], int n)
{
    memset(dp, -1, sizeof(dp));
    return game(arr, 0, n - 1);
}

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int T;
    cin >> T;
    while (T--)
    {
        //taking number of elements
        int N;
        cin >> N;

        int A[N];

        //inserting the elements
        for (int i = 0; i < N; i++)
            cin >> A[i];

        //calling function maximumAmount()
        cout << maximumAmount(A, N) << endl;

    }
    return 0;
}  // } Driver Code Ends