#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int game(int arr[], int n)
{
    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                           arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    // for (int i = 0; i<n; i++)
    // {
    //     for (int j = 0; j<n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[0][n - 1];
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
    cout << game(arr, n);
    return 0;
}
