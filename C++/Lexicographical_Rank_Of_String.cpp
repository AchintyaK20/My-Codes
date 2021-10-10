#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
#define CHAR 256
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
int main()
{
    SPEED;
    string str;
    cin >> str;
    int n = str.size();
    int count[CHAR] = {0};
    int mul = fact(n);
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    for (int i = 1; i < CHAR; i++)
    {
        count[i] += count[i - 1];
    }
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res += mul * (count[str[i] - 1]);
        for (int j = str[i]; j < CHAR; j++)
        {
            count[j]--;
        }
    }
    cout << res;
    return 0;
}