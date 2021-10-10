#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD 1000000007
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    ll freq[n + 1][n + 1];
    memset(freq, 0, sizeof(freq));
    umap u;
    rep(i,0,n)
    {
        u.clear();
        rep(j, i, n)    
        {
            if (j == 0)
            {
                u[a[j]]++;
                freq[i][j] = 0;
                continue;
            }
            if (u.find(a[j]) != u.end())
            {
                if (u[a[j]] == 1)
                {
                    freq[i][j] = freq[i][j - 1] + 2;
                }
                else
                {
                    freq[i][j] = freq[i][j - 1] + 1;
                }
            }
            else
            {
                freq[i][j] = freq[i][j - 1];
            }
            u[a[j]]++;
        }
    }
    ll totalTables = 100;
    ll dp[101][1001];
    memset(dp, 0, sizeof(dp));
    rep(i, 1, n + 1)
    {
        dp[1][i] = freq[0][i - 1];
    }
    rep(i, 2, 101)
    {
        rep(j, 2, n + 1)
        {
            ll minIff =1e18;
            rep(c, 1, j)
            {
                minIff = min(minIff, dp[i - 1][c] + freq[c][j - 1]);
            }
            dp[i][j] = minIff;
        }
    }
    ll ans = INT_MAX;
    rep(x, 1, 101)
    {
        ans = min(ans, (x * k) + dp[x][n]);
    }
    cout << ans << endl;
    // rep(i,1,101)
    // {
    //     rep(j,1,n+1)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}