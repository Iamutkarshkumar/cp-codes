// Assignment 8:Implement a backtracking algorithm for solving a constraint satisfaction problem, the N
// Queens problem, Sudoku. 

#include <bits/stdc++.h>
using namespace std;

// ===== N-Queens =====
void solveNQueens(int n) {
    vector<int> cols(n, -1);
    vector<bool> usedCol(n, false), diag1(2*n, false), diag2(2*n, false);
    vector<vector<string>> solutions;
    function<void(int)> backtrack = [&](int row) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int r = 0; r < n; ++r)
                board[r][cols[r]] = 'Q';
            solutions.push_back(board);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (usedCol[c] || diag1[row+c] || diag2[row-c+n]) continue;
            cols[row] = c;
            usedCol[c] = diag1[row+c] = diag2[row-c+n] = true;
            backtrack(row+1);
            usedCol[c] = diag1[row+c] = diag2[row-c+n] = false;
        }
    };
    backtrack(0);
    cout << "Found " << solutions.size() << " solutions for " << n << "-Queens\n";
    for (auto &board : solutions) {
        for (auto &row : board) cout << row << "\n";
        cout << "\n";
    }
}

// ===== Sudoku =====

bool solveSudoku(vector<vector<int>>& board) {
    vector<vector<bool>> rowUsed(9, vector<bool>(10,false)), colUsed(9, vector<bool>(10,false)), boxUsed(9, vector<bool>(10,false));
    // initialize
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int v = board[r][c];
            if (v) {
                rowUsed[r][v] = colUsed[c][v] = boxUsed[(r/3)*3 + c/3][v] = true;
            }
        }
    }
    function<bool(int,int)> backtrack = [&](int r, int c) -> bool {
        if (r == 9) return true;
        int nr = (c == 8 ? r+1 : r);
        int nc = (c == 8 ? 0 : c+1);
        if (board[r][c] != 0) return backtrack(nr,nc);
        for (int v = 1; v <= 9; ++v) {
            int b = (r/3)*3 + c/3;
            if (rowUsed[r][v] || colUsed[c][v] || boxUsed[b][v]) continue;
            board[r][c] = v;
            rowUsed[r][v] = colUsed[c][v] = boxUsed[b][v] = true;
            if (backtrack(nr,nc)) return true;
            board[r][c] = 0;
            rowUsed[r][v] = colUsed[c][v] = boxUsed[b][v] = false;
        }
        return false;
    };
    return backtrack(0,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Select problem: 1) N-Queens  2) Sudoku\n";
    int choice; cin >> choice;
    if (choice == 1) {
        cout << "Enter N: "; int n; cin >> n;
        solveNQueens(n);
    } else if (choice == 2) {
        vector<vector<int>> board(9, vector<int>(9));
        cout << "Enter Sudoku (9 lines of 9 digits, use 0 for blanks):\n";
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) cin >> board[r][c];
        }
        if (solveSudoku(board)) {
            cout << "Solved Sudoku:\n";
            for (auto &row : board) {
                for (int v : row) cout << v << " ";
                cout << "\n";
            }
        } else cout << "No solution exists.\n";
    } else {
        cout << "Invalid choice\n";
    }
    return 0;
}
