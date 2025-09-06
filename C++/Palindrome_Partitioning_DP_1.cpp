#include <iostream>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int palPart(string &s, int n)
{
    int dp[n][n];
    bool isPal[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        isPal[i][i] = true;
    }
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (gap == 1)
            {
                isPal[i][j] = (s[i] == s[j]);
            }
            else
            {
                isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
            }
            if (isPal[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    SPEED;
    string s;
    cin >> s;
    int n = s.size();
    cout << palPart(s, n);
    return 0;
}