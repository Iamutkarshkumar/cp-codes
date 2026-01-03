#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void floydWarshall(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Replace -1 with a large value to indicate no edge between nodes
    const int INF = 1e9;  // A large value representing infinity
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == -1 && i != j) {
                matrix[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Restore -1 for unreachable pairs
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] >= INF) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 43},
        {1, 0, 6},
        {-1, -1, 0}
    };

    floydWarshall(matrix);

    // Output the result
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
