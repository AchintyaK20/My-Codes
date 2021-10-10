#include <bits/stdc++.h>
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

int minJumps(vt<int> &a)
{
    int n = sz(a);
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0 ; j < i ; j++)
        {
            if (dp[j] != INT_MAX)
            {
                if (a[j] + j >= i)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]);
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
    cout << minJumps(a) << endl;
    return 0;
}