#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int minCoins(int arr[], int n, int val)
{
    int dp[val + 1];
    dp[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INT_MAX)
                {
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }
    return dp[val];
}
int main()
{
    SPEED;
    int n, val;
    cin >> n >> val;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minCoins(arr, n, val);
    return 0;
}