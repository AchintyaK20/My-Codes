#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool isPalin(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
int palPart(string &s, int i, int j)
{
    if (isPalin(s, i, j))
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i; k < j; k++)
    {
        res = min(res, 1 + palPart(s, i, k) + palPart(s, k + 1, j));
    }
    return res;
}
int main()
{
    SPEED;
    string s;
    cin >> s;
    int n = s.size();
    cout << palPart(s, 0, n - 1);
    return 0;
}