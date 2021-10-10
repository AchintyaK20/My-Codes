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

void initialize(vt<int> &parent, vt<int> &rank)
{
    for (int i = 0 ; i < sz(parent) ; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Using Path Compression
int FIND(int x, vt<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = FIND(parent[x], parent);
    return parent[x];
}

void uni(int x, int y, vt<int> &par,vt<int> &rank)
{
    par[FIND(x, par)] = FIND(y, par);
}
// Union By Rank
void UNION(int x, int y, vt<int> &parent , vt<int> &rank)
{
    int repX = FIND(x, parent);
    int repY = FIND(y, parent);
    if (repX == repY)
    {
        return;
    }
    if (rank[repX] < rank[repY])
    {
        parent[repX] = repY;
    }
    else if (rank[repX] > rank[repY])
    {
        parent[repY] = repX;
    }
    else
    {
        parent[repY] = repX;
        rank[repX]++;
    }
}

bool isConnected(int x, int y, vt<int> &parent)
{
    return (FIND(x, parent) == FIND(y, parent));
}

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    vt<int> parent(n), rank(n);
    initialize(parent, rank);
    int q;
    cin >> q;
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        UNION(x, y, parent, rank);
    }
    cout << isConnected(1, 3, parent);
    return 0;
}