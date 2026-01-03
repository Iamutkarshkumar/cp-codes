// // #include <bits/stdc++.h>
// // using namespace std;
// // #define gc getchar_unlocked
// // #define fo(i, n) for (i = 0; i < n; i++)
// // #define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
// // #define ll long long
// // #define deb(x) cout << #x << "=" << x << endl
// // #define pb push_back
// // #define mp make_pair
// // #define F first
// // #define S second
// // #define all(x) x.begin(), x.end()
// // #define clr(x) memset(x, false, sizeof(x))
// // #define sortall(x) sort(all(x))
// // #define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
// // #define PI 3.1415926535897932384626
// // #define mod 1000000007
// // typedef pair<int, int> pii;
// // typedef pair<ll, ll> pl;
// // typedef vector<int> vi;
// // typedef vector<ll> vl;
// // typedef vector<pii> vpii;
// // typedef vector<pl> vpl;
// // typedef vector<vi> vvi;
// // typedef vector<vl> vvl;
// // int main(){
// //     int t;
// //     cin>>t;
// //     while(t--){
        
// //     }

// // }
// #include <bits/stdc++.h>

// using namespace std;

// #define MAX_N 200000

// iint directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// // Function to count the number of connected regions
// int countRegions(const vector<string>& grid, int n) {
//     vector<vector<bool>> visited(2, vector<bool>(n, false));
//     int regions = 0;
    
//     auto inBounds = [&](int r, int c) {
//         return r >= 0 && r < 2 && c >= 0 && c < n;
//     };
    
//     auto bfs = [&](int r, int c) {
//         queue<pair<int, int>> q;
//         q.push(make_pair(r, c));
//         visited[r][c] = true;
        
//         while (!q.empty()) {
//             pair<int, int> p = q.front(); q.pop();
//             int x = p.first, y = p.second;
//             for (int i = 0; i < 4; ++i) {
//                 int nx = x + directions[i][0], ny = y + directions[i][1];
//                 if (inBounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.') {
//                     visited[nx][ny] = true;
//                     q.push(make_pair(nx, ny));
//                 }
//             }
//         }
//     };

//     for (int i = 0; i < 2; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (grid[i][j] == '.' && !visited[i][j]) {
//                 bfs(i, j);
//                 ++regions;
//             }
//         }
//     }
    
//     return regions;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
        
//         vector<string> grid(2);
//         cin >> grid[0];
//         cin >> grid[1];
        
//         int initialRegions = countRegions(grid, n);
//         if (initialRegions == 3) {
//             cout << "0\n";
//             continue;
//         }
        
//         int count = 0;
        
//         // Check each cell if turning it into 'x' would give exactly 3 regions
//         for (int i = 0; i < 2; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == '.') {
//                     // Temporarily mark the cell as blocked
//                     grid[i][j] = 'x';
                    
//                     int newRegions = countRegions(grid, n);
                    
//                     if (newRegions == 3) {
//                         ++count;
//                     }
                    
//                     // Restore the cell back to free
//                     grid[i][j] = '.';
//                 }
//             }
//         }
        
//         cout << count << "\n";
//     }
    
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Directions for 4-connectivity (left, right, up, down)
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Function to count the number of connected regions
int countRegions(const vector<string>& grid, int n) {
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    int regions = 0;
    
    auto inBounds = [&](int r, int c) {
        return r >= 0 && r < 2 && c >= 0 && c < n;
    };
    
    auto bfs = [&](int r, int c) {
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        visited[r][c] = true;
        
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (inBounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    };

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                ++regions;
            }
        }
    }
    
    return regions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> grid(2);
        cin >> grid[0];
        cin >> grid[1];
        
        int initialRegions = countRegions(grid, n);
        if (initialRegions == 3) {
            cout << "0\n";
            continue;
        }
        
        int count = 0;
        
        // Check each cell if turning it into 'x' would give exactly 3 regions
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    // Temporarily mark the cell as blocked
                    grid[i][j] = 'x';
                    
                    int newRegions = countRegions(grid, n);
                    
                    if (newRegions == 3) {
                        ++count;
                    }
                    
                    // Restore the cell back to free
                    grid[i][j] = '.';
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
