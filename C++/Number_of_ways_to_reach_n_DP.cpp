#include <bits/stdc++.h>
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define rep(i, x, n) for (int i = (x); i < (n); i++)
#define per(i, n, x) for (int i = (n); i >= (x); i--)
#define tr(x, v) for (auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define CEIL(a, b) (a + b - 1) / (b)
#define endl '\n'
#define db1(x) cerr << #x << " = " << x << '\n';
#define db2(v)                 \
    cerr << #v << " = ";       \
    tr(x, v) cerr << x << " "; \
    cerr << '\n';
#define present(m, x) (m.find(x) != m.end())
#define umap unordered_map
#define uset unordered_set
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vvi;

int countWays(int n)
{
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = (dp[j] % MOD + dp[j - i] % MOD) % MOD;
        }
        db2(dp)
    }
    return dp[n];
}
void SOLVE()
{
    int n;
    cin >> n;
    cout << countWays(n);
}

int main()
{
    FAST_IO;
    int T = 1;
    //    cin >> T;
    rep(tc, 1, T + 1)
    {
        // cout << "Case #" << tc << ": ";
        SOLVE();
    }
    return 0;
}