#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int bst(int n)
{
    int dp[n + 1];
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
int main()
{
    SPEED;
    int n;
    cin >> n;
    cout << bst(n);
    return 0;
}