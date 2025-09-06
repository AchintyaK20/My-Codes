#include <iostream>
#define pi pair<int, int>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void addEdgeUndirected(int u, int v, vector<vector<int>> &adj) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addEdgeDirected(int u, int v, vector<vector<int>> &adj) {
    adj[u].push_back(v);
}

void addEdgeWeightedDirected(int u, int v, int wt, vector<pair<int, int>> adj[]) {
    adj[u].push_back({v, wt});
}

void addEdgeWeightedUndirected(int u, int v, int wt, vector<pair<int, int>> adj[]) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
void printEdge(vector<int> adj[], int V) {
    for (int i = 0; i < V; i++) {
        for (int &x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
void BFSDis(vector<int> adj[], int s, vector<bool> &visited) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            BFSDis(adj, i, visited);
        }
    }
}
void DFSRec(int s, vector<int> adj[], vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";
    for (int v : adj[s]) {
        if (!visited[v]) {
            DFSRec(v, adj, visited);
        }
    }
}
void DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSRec(i, adj, visited);
        }
    }
}

void shortestPathinDAG(vector<pair<int, int>> adj[], int V, int src) {
    stack<int> topSort = topologicalSortingDFS(adj, V);
    vector<int> dist(V, INF);
    dist[src] = 0;
    while (!topSort.empty()) {
        int u = topSort.top();
        topSort.pop();
        for (auto &x : adj[u]) {
            int v = x.first, wt = x.second;
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
}

void DijkstraShortestPath(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;  // Min-Heap (Ordered by first value)
    vector<int> dist(V, INF);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

void BellmanFordAlgorithm(vector<pair<int, int>> adj[], int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    for (int count = 1; count <= V - 1; count++) {
        for (int u = 0; u < V; u++) {
            for (auto &x : adj[u]) {
                int v = x.first;
                int weight = x.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
}

void APUtil(vector<int> adj[], vector<bool> &vis, vector<int> &dis, vector<int> &low, vector<bool> &AP,
            vector<int> &parent, int u) {
    static int time = 0;
    int children = 0;
    vis[u] = true;
    dis[u] = low[u] = ++time;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            children++;
            APUtil(adj, vis, dis, low, AP, parent, v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1) {
                AP[u] = true;
            }
            if (parent[u] != -1 && low[v] >= dis[u]) {
                AP[u] = true;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], dis[v]);
        }
    }
}

void ArticulationPoint(vector<int> adj[], int V) {
    vector<bool> AP(V, false), vis(V, false);
    vector<int> dis(V), low(V), parent(V, -1);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            APUtil(adj, vis, dis, low, AP, parent, i);
        }
    }
    for (int i = 0; i < V; i++) {
        if (AP[i]) {
            cout << i << " ";
        }
    }
}

void shortestPathUnweightedGraph(vector<int> adj[], int V, int source) {
    vector<int> dist(V, INT_MIN);
    dist[source] = 0;
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (auto &x : dist) {
        cout << x << " ";
    }
}

bool detectCycleUndirectedGraphDFS(vector<int> adj[], int u, int parent, vector<bool> &vis) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            if (detectCycleUndirectedGraphDFS(adj, v, u, vis)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool detectCycleUndirectedGraphDFS(vector<int> adj[], int V) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycleUndirectedGraphDFS(adj, i, -1, vis)) {
                return true;
            }
        }
    }
    return false;
}

bool detectCycleDirectedGraphDFS(vector<int> adj[], int u, vector<bool> &vis, vector<bool> &recStack) {
    vis[u] = true;
    recStack[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            if (detectCycleDirectedGraphDFS(adj, v, vis, recStack)) {
                return true;
            }
        } else if (recStack[v]) {
            return true;
        }
    }
    recStack[u] = false;
    return false;
}

bool detectCycleDirectedGraphDFS(vector<int> adj[], int V) {
    vector<bool> vis(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycleDirectedGraphDFS(adj, i, vis, recStack)) {
                return true;
            }
        }
    }
    return false;
}

void topologicalSortBFS(vector<int> adj[], int V) {
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto &x : adj[i]) {
            indeg[x]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto &v : adj[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
        ++count;
    }
    bool hasCycle = (count != V);
    cout << "Has Cycle: " << hasCycle << "\n";
}

void topologicalSortingDFS(vector<int> adj[], int u, stack<int> &st, vector<bool> &vis) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            topologicalSortingDFS(adj, v, st, vis);
        }
    }
    st.push(u);
}

stack<int> topologicalSortingDFS(vector<int> adj[], int V) {
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topologicalSortingDFS(adj, i, st, vis);
        }
    }
    return st;
}

int main() {
    SPEED;
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdgeUndirected(u, v, adj);
    }
    ArticulationPoint(adj, V);
    return 0;
}
