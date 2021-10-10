#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dp[100][100];
int mChain(int arr[], int i, int j)
{
    if (i + 1 == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX, temp;
    for (int k = i + 1; k < j; k++)
    {
        temp = mChain(arr, i, k) + mChain(arr, k, j) + arr[i] * arr[k] * arr[j];
        res = min(res, temp);
    }
    return dp[i][j] = res;
}
int main()
{
    SPEED;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << mChain(arr, 0, n - 1);
    return 0;
}