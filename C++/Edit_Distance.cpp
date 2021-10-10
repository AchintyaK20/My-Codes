#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dp[100][100];
int eD(string &s1, string &s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = eD(s1, s2, m - 1, n - 1);
    else
        return dp[m][n] = 1 + min(eD(s1, s2, m, n - 1), min(eD(s1, s2, m - 1, n), eD(s1, s2, m - 1, n - 1)));
}
int main()
{
    SPEED;
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    memset(dp, -1, sizeof(dp));
    cout << eD(s1, s2, m, n);
    return 0;
}