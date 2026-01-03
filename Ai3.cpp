// Assignment 3: Write a program to implement heuristic-based search algorithms; A* and Greedy Best-First 
// Search

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

struct Node {
    int r, c;
    int g, h;
    // For A*: f = g + h; For GBFS: use h only.
};

// Compare for priority queue
struct CompareAStar {
    bool operator()(const Node &a, const Node &b) const {
        return (a.g + a.h) > (b.g + b.h);
    }
};
struct CompareGreedy {
    bool operator()(const Node &a, const Node &b) const {
        return a.h > b.h;
    }
};

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int manhattan(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

pair<int, vector<pair<int,int>>> astar(const vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> closed(R, vector<bool>(C, false));
    vector<vector<pair<int,int>>> parent(R, vector<pair<int,int>>(C, {-1,-1}));
    priority_queue<Node, vector<Node>, CompareAStar> open;

    open.push({0, 0, 0, manhattan(0,0,R-1,C-1)});

    while (!open.empty()) {
        Node cur = open.top(); open.pop();
        if (closed[cur.r][cur.c]) continue;
        closed[cur.r][cur.c] = true;

        if (cur.r == R-1 && cur.c == C-1) {
            // reconstruct path
            vector<pair<int,int>> path;
            int cr = cur.r, cc = cur.c;
            while (!(cr == 0 && cc == 0)) {
                path.push_back({cr, cc});
                tie(cr, cc) = parent[cr][cc];
            }
            path.push_back({0,0});
            reverse(path.begin(), path.end());
            return {cur.g, path};
        }

        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == 1 || closed[nr][nc]) continue;
            int ng = cur.g + 1;
            open.push({nr, nc, ng, manhattan(nr,nc,R-1,C-1)});
            parent[nr][nc] = {cur.r, cur.c};
        }
    }
    return {-1, {}}; // no path
}

pair<int, vector<pair<int,int>>> greedy_best_first(const vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> closed(R, vector<bool>(C, false));
    vector<vector<pair<int,int>>> parent(R, vector<pair<int,int>>(C, {-1,-1}));
    priority_queue<Node, vector<Node>, CompareGreedy> open;

    open.push({0, 0, 0, manhattan(0,0,R-1,C-1)});

    while (!open.empty()) {
        Node cur = open.top(); open.pop();
        if (closed[cur.r][cur.c]) continue;
        closed[cur.r][cur.c] = true;

        if (cur.r == R-1 && cur.c == C-1) {
            vector<pair<int,int>> path;
            int cr = cur.r, cc = cur.c;
            while (!(cr == 0 && cc == 0)) {
                path.push_back({cr, cc});
                tie(cr, cc) = parent[cr][cc];
            }
            path.push_back({0,0});
            reverse(path.begin(), path.end());
            return {cur.g, path};
        }

        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == 1 || closed[nr][nc]) continue;
            int ng = cur.g + 1;
            open.push({nr, nc, ng, manhattan(nr,nc,R-1,C-1)});
            parent[nr][nc] = {cur.r, cur.c};
        }
    }
    return {-1, {}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R = 50, C = 50;
    double obstacle_prob = 0.2;
    vector<vector<int>> grid(R, vector<int>(C, 0));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0,1);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (!(i==0 && j==0) && !(i==R-1 && j==C-1) && dis(gen) < obstacle_prob)
                grid[i][j] = 1;

    cout << "Grid " << R << "x" << C << " with " << (int)(obstacle_prob*100)
         << "% obstacles generated.\n";

    auto t1 = high_resolution_clock::now();
    auto [costA, pathA] = astar(grid);
    auto t2 = high_resolution_clock::now();
    auto tA = duration_cast<milliseconds>(t2-t1).count();
    if (costA>=0)
        cout << "A* found path length " << costA << " in " << tA << " ms\n";
    else cout << "A* found no path (" << tA << " ms)\n";

    t1 = high_resolution_clock::now();
    auto [costG, pathG] = greedy_best_first(grid);
    t2 = high_resolution_clock::now();
    auto tG = duration_cast<milliseconds>(t2-t1).count();
    if (costG>=0)
        cout << "Greedy best-first found path length " << costG << " in " << tG << " ms\n";
    else cout << "Greedy best-first found no path (" << tG << " ms)\n";

    return 0;
}