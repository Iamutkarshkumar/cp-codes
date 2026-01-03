// #include <bits/stdc++.h>
// using namespace std;
// #define gc getchar_unlocked
// #define fo(i, n) for (i = 0; i < n; i++)
// #define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
// #define ll long long
// #define deb(x) cout << #x << "=" << x << endl
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
// #define all(x) x.begin(), x.end()
// #define clr(x) memset(x, false, sizeof(x))
// #define sortall(x) sort(all(x))
// #define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
// #define PI 3.1415926535897932384626
// #define mod 1000000007
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpii;
// typedef vector<pl> vpl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// void file_i_o(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// }
// vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// bool isSafe(int n,int m,int x,int y){
//     return (x >= 0 && x < n && y >= 0 && y < m);
// }
// int main(){
//     file_i_o();
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;cin>>n>>m;
//         vector<vector<int>> v(n, vector<int>(m));
//         vector<vector<int>> visited(n, vector<int>(m, false));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 cin >> v[i][j];
//             }
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!visited[i][j] and v[i][j]>0){
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     visited[i][j] = true;
//                     int vol=0;
//                     while(!q.empty()){
//                         int x= q.front().first;
//                         int y= q.front().second;
//                         q.pop();
//                         vol += v[x][y];
//                         for(auto dir: directions){
//                             int x_= x + dir[0];
//                             int y_= y + dir[1];
//                             if(isSafe(n, m, x_, y_) && !visited[x_][y_] && v[x_][y_] > 0){
//                                 visited[x_][y_] = true;
//                                 q.push({x_, y_});
//                             }
//                         }
//                     }
//                     ans= max(ans, vol);
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
// }

class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};