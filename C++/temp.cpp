#include <bits/stdc++.h>
using namespace std;

const int maxn = 300011;
vector<int> adj[maxn];
int deg[maxn], d[maxn];
char s[maxn];

int Find(int u, int c)
{
    if (d[u] != -1)
    {
        return d[u];
    }
    d[u] = 0;
    for (int v : adj[u])
    {
        d[u] = max(d[u], Find(v, c));
    }
    d[u] += (s[u] == c + 'a');
    return d[u];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cin >> (s + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++deg[v];
    }
    int count = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
            q.push(i), ++count;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (--deg[v] == 0)
                q.push(v), ++count;
        }
    }
    if (count < n)
    {
        cout << "-1";
    }
    else
    {
        int ans = 0;
        for (int c = 0; c < 26; ++c)
        {
            memset(d, -1, sizeof(d));
            for (int i = 1; i <= n; ++i)
            {
                ans = max(ans, Find(i, c));
            }
        }
        cout << ans;
    }
}