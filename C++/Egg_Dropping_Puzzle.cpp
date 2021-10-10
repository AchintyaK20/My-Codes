#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dp[101][10001];
int eggDrop(int e, int f)
{
    if (e == 1)
        return f;
    if (f == 1 || f == 0)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int res = INT_MAX;
    // Consider all droppings from
    // 1st floor to fth floor and
    // return the minimum of these
    // values plus 1.
    for (int x = 1; x <= f; x++)
    {
        int sub_res = max(eggDrop(e - 1, x - 1), eggDrop(e, f - x));
        if (sub_res != INT_MAX)
        {
            res = min(res, sub_res + 1);
        }
    }
    return dp[e][f] = res;
}
int main()
{
    SPEED;
    int e, f;
    cin >> e >> f;
    memset(dp, -1, sizeof(dp));
    cout << eggDrop(e, f);
    return 0;
}