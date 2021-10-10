// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    vector<int> key(V, INT_MAX);
    key[0] = 0;
    int ans = 0;
    vector<bool> vis(V, false);
    for (int count = 0 ; count < V ; count++)
    {
        int u = -1;
        for (int i = 0; i < V ; i++)
        {
            if (!vis[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        vis[u] = true;
        ans += key[u];
        for (int v = 0 ; v < V ; v++)
        {
            if (graph[u][v] != 0 && !vis[v])
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return ans;
}