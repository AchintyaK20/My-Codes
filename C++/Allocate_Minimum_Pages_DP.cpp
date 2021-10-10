#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void storeSum(int arr[], int n, vector<vector<int>> &sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                sum[i][j] = arr[i];
            }
            else
            {
                sum[i][j] = sum[i][j - 1] + arr[j];
            }
        }
    }
}
int minPages(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    vector<vector<int>> sum(n, vector<int>(n, 0));
    storeSum(arr, n, sum);
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = dp[1][j - 1] + arr[j - 1];
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i][1] = arr[0];
    }
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = INT_MAX;
            for (int idx = 1; idx < j; idx++)
            {

                dp[i][j] = min(dp[i][j], max(dp[i - 1][idx], sum[idx][j - 1]));
            }
        }
    }
    return dp[k][n];
}
int main()
{
    SPEED;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minPages(arr, n, k);
    return 0;
}