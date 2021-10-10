#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void findAllPalindrome(string &s, vector<vector<bool>> &isPal)
{
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                isPal[i][j] = true;
            }
            else if (s[i] == s[j])
            {
                if (j - i == 1)
                {
                    isPal[i][j] = true;
                }
                else
                {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }
    }
}
int palPart(string &s, int n)
{
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    findAllPalindrome(s, isPal);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        if (isPal[0][i])
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = INT_MAX;
            for (int j = i; j > 0; j--)
            {
                if (isPal[j][i])
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }
    return dp[n - 1];
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