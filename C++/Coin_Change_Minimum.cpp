#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dp[100];
int coinChange(int arr[], int n, int sum)
{
    if (sum == 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sum)
        {
            int sub_res = coinChange(arr, n, sum - arr[i]);
            if (sub_res != INF)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return dp[sum] = res;
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
    memset(dp, -1, sizeof(dp));
    cout << coinChange(arr, n, sum);
    return 0;
}