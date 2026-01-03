// assignment 1: Implement and compare the performance of Breadth-First Search (BFS) and Depth-First 
// Search (DFS) on a maze or graph traversal problem. 

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Generate a random connected undirected graph
vector<vector<int>> generate_random_graph(int n, int m) {
    vector<vector<int>> adj(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n - 1);

    // ensure connectivity by creating a spanning tree
    for (int i = 1; i < n; ++i) {
        int j = dis(gen) % i;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    // add remaining edges randomly
    int extra = m - (n - 1);
    while (extra-- > 0) {
        int u = dis(gen), v = dis(gen);
        if (u == v) continue;
        // avoid duplicate edges
        if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    return adj;
}

void bfs(const vector<vector<int>>& adj, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs_util(const vector<vector<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_util(adj, v, visited);
        }
    }
}

void dfs(const vector<vector<int>>& adj, int start, vector<bool>& visited) {
    dfs_util(adj, start, visited);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 100000;    // number of nodes
    int m = 200000;    // number of edges
    cout << "Generating random graph with " << n << " nodes and " << m << " edges...\n";
    auto adj = generate_random_graph(n, m);
    cout << "Graph generated.\n";

    vector<bool> visited;
    
    // Time BFS
    visited.assign(n, false);
    auto t1 = high_resolution_clock::now();
    bfs(adj, 0, visited);
    auto t2 = high_resolution_clock::now();
    auto bfs_duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "BFS took " << bfs_duration << " ms" << "\n";

    // Time DFS
    visited.assign(n, false);
    t1 = high_resolution_clock::now();
    dfs(adj, 0, visited);
    t2 = high_resolution_clock::now();
    auto dfs_duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "DFS took " << dfs_duration << " ms" << "\n";

    return 0;
}
