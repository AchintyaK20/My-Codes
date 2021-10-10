#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int eD(string &s1, string &s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[m][n];
}
int main()
{
    SPEED;
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    cout << eD(s1, s2, m, n);
    return 0;
}