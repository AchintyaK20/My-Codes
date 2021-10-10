#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

long long dp[100];
long long bst(long long n)
{
    if (n == 0 || n == 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += bst(i - 1) * bst(n - i);
    }
    return dp[n] = res;
}
int main()
{
    SPEED;
    long long n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << bst(n);
    return 0;
}