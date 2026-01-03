// Assignment 9: Write a program to solve the N-Queens problem using local search strategies (e.g., min
// conflicts heuristic) and analyze the effectiveness compared to backtracking. 

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ---- Backtracking (find one solution) ----
bool bt_place(int row, int n, vector<int>& cols, vector<bool>& usedCol, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) return true;
    for (int c = 0; c < n; ++c) {
        if (usedCol[c] || diag1[row + c] || diag2[row - c + n]) continue;
        cols[row] = c;
        usedCol[c] = diag1[row + c] = diag2[row - c + n] = true;
        if (bt_place(row + 1, n, cols, usedCol, diag1, diag2)) return true;
        usedCol[c] = diag1[row + c] = diag2[row - c + n] = false;
    }
    return false;
}

bool solve_backtracking(int n, vector<int>& solution) {
    vector<int> cols(n);
    vector<bool> usedCol(n, false), diag1(2*n, false), diag2(2*n, false);
    if (bt_place(0, n, cols, usedCol, diag1, diag2)) {
        solution = cols;
        return true;
    }
    return false;
}

// ---- Min-Conflicts Local Search ----
vector<int> solve_min_conflicts(int n, int max_steps) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_col(0, n-1);

    // initial: one queen per row, random column
    vector<int> cols(n);
    for (int i = 0; i < n; ++i) cols[i] = dist_col(gen);

    // conflict counters
    vector<int> col_count(n, 0), diag1_count(2*n, 0), diag2_count(2*n, 0);
    auto conflict = [&](int r, int c) {
        return col_count[c] + diag1_count[r+c] + diag2_count[r-c+n] - 3;
    };
    // init counts
    for (int r = 0; r < n; ++r) {
        int c = cols[r];
        col_count[c]++;
        diag1_count[r+c]++;
        diag2_count[r-c+n]++;
    }

    for (int step = 0; step < max_steps; ++step) {
        // find rows in conflict
        vector<int> conflicted;
        for (int r = 0; r < n; ++r) if (conflict(r, cols[r]) > 0) conflicted.push_back(r);
        if (conflicted.empty()) return cols; // solved

        // pick random conflicted row
        int row = conflicted[gen() % conflicted.size()];
        // find column with minimal conflicts
        int best_c = cols[row];
        int min_conf = INT_MAX;
        for (int c = 0; c < n; ++c) {
            int conf = col_count[c] + diag1_count[row+c] + diag2_count[row-c+n];
            if (r == row && c == cols[row]) conf -= 3;
            if (conf < min_conf) {
                min_conf = conf;
                best_c = c;
            }
        }
        
        // move queen
        int old_c = cols[row];
        // update counts
        col_count[old_c]--; diag1_count[row+old_c]--; diag2_count[row-old_c+n]--;
        cols[row] = best_c;
        col_count[best_c]++; diag1_count[row+best_c]++; diag2_count[row-best_c+n]++;
    }
    return {}; // fail
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;
    
    // Backtracking
    vector<int> sol_bt;
    auto t1 = high_resolution_clock::now();
    bool ok_bt = solve_backtracking(n, sol_bt);
    auto t2 = high_resolution_clock::now();
    auto dur_bt = duration_cast<milliseconds>(t2 - t1).count();
    if (ok_bt) {
        cout << "Backtracking solution found in " << dur_bt << " ms" << "\n";
    } else cout << "Backtracking failed" << "\n";

    // Min-Conflicts
    int max_steps = n * 100;
    auto t3 = high_resolution_clock::now();
    auto sol_mc = solve_min_conflicts(n, max_steps);
    auto t4 = high_resolution_clock::now();
    auto dur_mc = duration_cast<milliseconds>(t4 - t3).count();
    if (!sol_mc.empty()) {
        cout << "Min-Conflicts solution found in " << dur_mc << " ms" << "\n";
    } else cout << "Min-Conflicts failed in " << dur_mc << " ms" << "\n";

    return 0;
}