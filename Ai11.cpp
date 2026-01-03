// Assignment 11:Implementation of Travelling Salesman Problem1 

#include <bits/stdc++.h>
using namespace std;

double tsp_dp(const vector<vector<double>>& dist) {
    int n = dist.size();
    int N = 1 << n;
    const double INF = 1e18;
    // dp[mask][i]: minimum cost to visit set mask ending at i
    vector<vector<double>> dp(N, vector<double>(n, INF));
    dp[1][0] = 0; // start at city 0, mask bit0 = 1
    
    for (int mask = 1; mask < N; ++mask) {
        if (!(mask & 1)) continue; // must include start
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;
            double dpu = dp[mask][u];
            if (dpu >= INF) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                int next = mask | (1 << v);
                dp[next][v] = min(dp[next][v], dpu + dist[u][v]);
            }
        }
    }
    double ans = INF;
    int full = N - 1;
    // return to start (0)
    for (int u = 1; u < n; ++u) {
        ans = min(ans, dp[full][u] + dist[u][0]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<double>> dist(n, vector<double>(n));
    cout << "Enter distance matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    if (n > 20) {
        cout << "Warning: Exact DP TSP is exponential and may be slow for n > 20.\n";
    }

    double min_cost = tsp_dp(dist);
    cout << "Minimum TSP tour cost: " << min_cost << "\n";
    return 0;
}