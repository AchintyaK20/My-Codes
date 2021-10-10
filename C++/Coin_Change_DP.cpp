#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int coinChange(int coin[], int n, int sum)
{
    int dp[sum + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (coin[j - 1] <= i)
            {
                dp[i][j] = dp[i - coin[j - 1]][j] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[sum][n];
}
int main()
{
    SPEED;
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << coinChange(arr, n, sum);
    return 0;
}