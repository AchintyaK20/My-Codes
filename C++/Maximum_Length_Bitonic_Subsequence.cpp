#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define CEIL(a, b) (a + b - 1)/(b)
#define endl "\n"
#define db1(x) cerr << #x << " = " << x << "\n";
#define db2(v) for (auto &x : v) cerr << x <<" "; cerr << "\n";
#define umap unordered_map
#define uset unordered_set
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    rep(i, n)
    {
        cin >> arr[i];
    }
    vt<int> LIS(n, 1), LDS(n, 1);
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 0 ; j < i ; j++)
        {
            if (arr[i] > arr[j])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }
    for (int i = n - 2 ; i >= 0 ; i--)
    {
        for (int j = i + 1 ; j < n ; j++)
        {
            if (arr[i] > arr[j])
            {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }
    int ans = -INF;
    for (int i = 0 ; i < n ; i++)
    {
        ans = max(ans, LIS[i] + LDS[i] - 1);
    }
    cout << ans;
}

int main()
{
    FAST_IO;
    int T = 1;
//   cin >> T;
    rep(tc, T)
    {
        solve();
    }
    return 0;
}