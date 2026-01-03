// Assignment 2: Write a program to implement uninformed search algorithms; uniform cost search and 
// bidirectional search, depth limited search  

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Generate a random connected undirected weighted graph
vector<vector<pair<int,int>>> generate_random_weighted_graph(int n, int m, int maxw = 10) {
    vector<vector<pair<int,int>>> adj(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_node(0, n - 1);
    uniform_int_distribution<> dis_w(1, maxw);

    // ensure connectivity via spanning tree
    for (int i = 1; i < n; ++i) {
        int j = dis_node(gen) % i;
        int w = dis_w(gen);
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
    }
    
    // add remaining edges
    int extra = m - (n - 1);
    while (extra-- > 0) {
        int u = dis_node(gen), v = dis_node(gen);
        if (u == v) continue;
        int w = dis_w(gen);
        // avoid duplicate
        bool dup = false;
        for (auto &p : adj[u]) if (p.first == v) { dup = true; break; }
        if (dup) continue;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

// Uniform Cost Search: finds min-cost path from start to goal
vector<int> uniform_cost_search(const vector<vector<pair<int,int>>> &adj, int start, int goal) {
    int n = adj.size();
    const int INF = 1e9;
    vector<int> dist(n, INF), parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        if (u == goal) break;
        for (auto &edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[goal] == INF) return {};
    // reconstruct path
    vector<int> path;
    for (int cur = goal; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

// Bidirectional search on unweighted graph
bool bidirectional_search(const vector<vector<int>> &adj, int start, int goal) {
    int n = adj.size();
    if (start == goal) return true;

    vector<bool> vis1(n, false), vis2(n, false);
    queue<int> q1, q2;
    q1.push(start); vis1[start] = true;
    q2.push(goal); vis2[goal] = true;

    while (!q1.empty() && !q2.empty()) {
        // expand one level from start-frontier
        int sz1 = q1.size();
        while (sz1--) {
            int u = q1.front(); q1.pop();
            for (int v : adj[u]) {
                if (vis2[v]) return true;
                if (!vis1[v]) { vis1[v] = true; q1.push(v); }
            }
        }
        // expand one level from goal-frontier
        int sz2 = q2.size();
        while (sz2--) {
            int u = q2.front(); q2.pop();
            for (int v : adj[u]) {
                if (vis1[v]) return true;
                if (!vis2[v]) { vis2[v] = true; q2.push(v); }
            }
        }
    }
    return false;
}

// Depth-Limited Search (recursive DFS with limit)
bool dls_util(const vector<vector<int>> &adj, int u, int goal, int limit, vector<bool> &visited) {
    if (u == goal) return true;
    if (limit <= 0) return false;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dls_util(adj, v, goal, limit - 1, visited)) return true;
        }
    }
    return false;
}

bool depth_limited_search(const vector<vector<int>> &adj, int start, int goal, int limit) {
    int n = adj.size();
    vector<bool> visited(n, false);
    return dls_util(adj, start, goal, limit, visited);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10000, m = 30000;
    int start = 0, goal = n - 1;
    int depth_limit = 20;

    // Generate weighted graph for UCS
    auto wadj = generate_random_weighted_graph(n, m);
    // Build unweighted graph list for bidirectional & DLS
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u)
        for (auto &p : wadj[u])
            adj[u].push_back(p.first);

    cout << "Graph with " << n << " nodes and " << m << " edges created.\n";

    // Uniform Cost Search
    auto t1 = high_resolution_clock::now();
    auto path = uniform_cost_search(wadj, start, goal);
    auto t2 = high_resolution_clock::now();
    auto ucs_time = duration_cast<milliseconds>(t2 - t1).count();
    if (!path.empty()) {
        cout << "UCS found path of cost " << path.size() - 1 << " in " << ucs_time << " ms\n";
    } else cout << "UCS found no path (" << ucs_time << " ms)\n";

    // Bidirectional Search
    t1 = high_resolution_clock::now();
    bool bidir_found = bidirectional_search(adj, start, goal);
    t2 = high_resolution_clock::now();
    auto bidir_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Bidirectional search " << (bidir_found ? "succeeded" : "failed")
         << " in " << bidir_time << " ms\n";

    // Depth-Limited Search
    t1 = high_resolution_clock::now();
    bool dls_found = depth_limited_search(adj, start, goal, depth_limit);
    t2 = high_resolution_clock::now();
    auto dls_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Depth-Limited search (limit=" << depth_limit << ") "
         << (dls_found ? "found" : "did not find") << " goal in "
         << dls_time << " ms\n";

    return 0;
}
