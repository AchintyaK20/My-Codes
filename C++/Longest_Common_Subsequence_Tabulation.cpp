#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main()
{
    SPEED;
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[m][n] << endl;
    int i = m, j = n;
    int idx = dp[m][n];
    string lcs(idx, ' ');
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[idx - 1] = s1[i - 1];
            i--, j--, idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << lcs;
    return 0;
}