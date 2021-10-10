#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define ld long double
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vi>
#define pb push_back
#define F first
#define S second
#define rep(i, x, n) for (int i = (x); i < (n); i++)
#define per(i, n, x) for (int i = (n); i >= (x); i--)
#define tr(x, v) for (auto &x : v)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define CEIL(a, b) (a + b - 1)/(b)
#define endl '\n'
#define db1(x) cerr << #x << " = " << x << '\n';
#define db2(v) cerr << #v << " = "; tr(x, v) cerr << x << " "; cerr << '\n';
#define present(m, x) (m.find(x) != m.end())
#define umap unordered_map
#define uset unordered_set
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool sortbysec(const pi &a, const pi &b)
{
    return (a.S < b.S);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<pi> vec;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        vec.pb({x, y});
    }
    sort(vec.begin(), vec.end(), [](const pi & a, const pi & b)
    {
        return (a.S < b.S);
    });
    tr(x, vec)
    {
        cout << x.F << " " << x.S << endl;
    }
    return 0;
}