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

int Knapsack(int W, vt<int> &Wt, vt<int> &val, int n)
{
    // Base Case
    // If weight becomes zero or there
    // are no elements left.
    if (W == 0 || n == 0)
    {
        return 0;
    }
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (Wt[n - 1] > W)
    {
        return Knapsack(W, Wt, val, n - 1);
    }
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        return max(val[n - 1] + Knapsack(W - Wt[n - 1], Wt, val, n - 1), Knapsack(W, Wt, val, n - 1));
    }
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
    cout << Knapsack(W, Wt, val, n);
}