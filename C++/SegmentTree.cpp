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
#define db1(x) cout << #x << " = " << x << '\n';
#define db2(v)        \
    for (auto &x : v) \
        cout << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

int getMid(int ss, int se)
{
    return (ss + se) / 2;
}
int constructST(int ss, int se, int si, vt<int> &a, vt<int> &tree)
{
    if (ss == se)
    {
        tree[si] = a[ss];
        return a[ss];
    }
    int mid = getMid(ss, se);
    tree[si] = constructST(ss, mid, 2 * si + 1, a, tree) +
               constructST(mid + 1, se, 2 * si + 2, a, tree);
    return tree[si];
}
int getSum(int qs, int qe, int ss, int se, int si, vt<int> &tree)
{
    if (se < qs || ss > qe)
    {
        return 0;
    }
    if (qs <= ss && qe >= se)
    {
        return tree[si];
    }
    int mid = getMid(ss, se);
    return getSum(qs, qe, ss, mid, 2 * si + 1, tree) +
           getSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}
void update(int ss, int se, int i, int diff, int si, vt<int> &tree)
{
    if (i < ss || i > se)
    {
        return;
    }
    tree[si] = tree[si] + diff;
    if (ss < se)
    {
        int mid = getMid(ss, se);
        update(ss, mid, i, diff, 2 * si + 1, tree);
        update(mid + 1, se, i, diff, 2 * si + 2, tree);
    }
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
    vt<int> tree(4 * n, -1);
    constructST(0, n - 1, 0, a, tree);

    int i, value;
    cin >> i >> value;
    int diff = value - a[i];
    update(0, n - 1, i, diff, 0, tree);
    cout << getSum(0, 2, 0, n - 1, 0, tree);
    return 0;
}