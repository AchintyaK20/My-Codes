#include <bits/stdc++.h>
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define CEIL(a, b) (a + b - 1) / (b)
#define endl "\n"
#define db1(x) cerr << #x << " = " << x << "\n";
#define db2(v)        \
    for (auto &x : v) \
        cerr << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

int Knapsack(int W, vt<int> &Wt, vt<int> &val, int n, vt< vt<int> > &dp)
{
    for (int i = 1 ; i <= n ; i++)
    {
        for (int w = 1 ; w <= W ; w++)
        {
            if (Wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - Wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // for (int i = 0 ; i <= n ; i++)
    // {
    //     for (int j = 0 ; j <= W ; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][W];
}
int main()
{
    FAST_IO;
    int n, W;
    cin >> n >> W;
    vt<int> val(n);
    rep(i, n)
    {
        cin >> val[i];
    }
    vt<int> Wt(n);
    rep(i, n)
    {
        cin >> Wt[i];
    }
    vt< vt<int> >dp(n + 1, vt<int>(W + 1));
    for (int i = 0 ; i <= W ; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0 ; i <= n ; i++)
    {
        dp[i][0] = 0;
    }
    cout << Knapsack(W, Wt, val, n, dp);
}