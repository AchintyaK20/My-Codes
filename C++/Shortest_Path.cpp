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
#define sz(x) (ll)(x).size()
#define CEIL(a, b) (a + b - 1)/(b)
#define endl "\n"
#define db1(x) cerr << #x << " = " << x << "\n";
#define db2(v) for (auto &x : v) cerr << x <<" ";
#define umap unordered_map
#define uset unordered_set
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;

void ShortestPath(vt<int> adj[], int s, int V)
{
    vt<int> dist(V, INF);
    vt<bool> vis(V, false);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    rep(i, sz(dist))
    {
        cout << dist[i] << " ";
    }
}
int main()
{
    FAST_IO;
    int V, E;
    cin >> V >> E;
    vt<int> adj[V];
    rep(i, E)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ShortestPath(adj, 0, V);
    return 0;
}