#include <bits/stdc++.h>
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define CEIL(a, b) (a + b - 1) / (b)
#define endl "\n"
#define db1(x) cerr << #x << " = " << x << "\n";
#define db2(v)            \
    for (auto &x : v)     \
        cerr << x << " "; \
    cerr << "\n";
#define umap unordered_map
#define uset unordered_set
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;

int EggDropping(int e, int f)
{
    /* A 2D table where entry
    eggFloor[i][j] will represent
    minimum number of trials needed for
    i eggs and j floors. */
    int dp[e + 1][f + 1];

    // We need one trial for one floor and 0
    // trials for 0 floors
    for (int i = 1; i <= e; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    // We always need j trials for one egg
    // and j floors.
    for (int j = 0; j <= f; j++)
    {
        dp[1][j] = j;
    }
    // Fill rest of the entries in table using
    // optimal substructure property
    for (int i = 2; i <= e; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            dp[i][j] = INF;
            for (int x = 1; x <= j; x++)
            {
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }
    // for (int i = 0 ; i <= e ; i++)
    // {
    //     for (int j = 0 ; j <= f;  j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[e][f];
}
void solve()
{
    int egg, floor;
    cin >> egg >> floor;
    cout << EggDropping(egg, floor);
}

int main()
{
    FAST_IO;
    int T = 1;
    //    cin >> T;
    rep(tc, T)
    {
        solve();
    }
    return 0;
}