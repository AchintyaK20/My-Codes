#include <bits/stdc++.h>
#include <string.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define CEIL(a, b) (a + b - 1)/(b)
#define endl "\n"
#define db1(x) cerr << #x << " = " << x << "\n";
#define db2(v) for (auto &x : v) cerr << x <<" ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

int fun(vt<int> &a)
{
    int n = sz(a);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = max(dp[0], a[0]);
    dp[1] = max(dp[0], a[1]);
    for (int i = 2 ; i < n ; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    }
    return dp[n - 1];
}
int main()
{
    FAST_IO;
    int n;
    cin >> n;
    vt<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    cout << fun(a);
    return 0;
}