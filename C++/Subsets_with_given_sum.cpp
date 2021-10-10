#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int a[MAX];
int dp[MAX][MAX];

int SS(int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0 ? 1 : 0);
    }
    if (sum < 0)
    {
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    int x = SS(n - 1, sum - a[n - 1]);
    int y = SS(n - 1, sum);
    return dp[n][sum] = x + y;
}
int main()
{
    int i, SUM, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> SUM;
    memset(dp, -1, sizeof(dp));
    int ans = SS(n, SUM);
    cout << ans;
}