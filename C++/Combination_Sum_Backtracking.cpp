#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
#define ld long double
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vi>
#define pb push_back
#define F first
#define S second
#define rep(i, x, n) for (int i = (x); i < (n); ++i)
#define tr(x, v) for (auto &x : v)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define CEIL(a, b) (a + b - 1) / (b)
#define endl '\n'
#define db1(x) cerr << #x << " = " << x << '\n';
#define db2(v) cerr << #v << " = "; tr(x, v) cerr << x << " "; cerr << '\n';
#define umap unordered_map
#define uset unordered_set
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
// clang-format on

void SUM(int start, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &v)
{
    if (sum == 0)
    {
        ans.push_back(v);
        return;
    }
    for (int i = start; i < sz(arr); i++)
    {
        if (arr[i] <= sum)
        {
            v.push_back(arr[i]);
            SUM(i, sum - arr[i], arr, ans, v);
            v.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> v;
    SUM(0, sum, arr, ans, v);
    return ans;
}

int32_t main()
{
    SPEED;
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    tr(x, arr) cin >> x;
    vector<vector<int>> vec = combinationSum(arr, sum);
    tr(x, vec)
    {
        tr(i, x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}