// //   ___  _                     __  __           ____        _     _           _       
// //  / _ \| |__   ___ _   _     |  \/  | ___     / ___| _   _| |__ (_) ___  ___| |_ ___ 
// // | | | | '_ \ / _ \ | | |    | |\/| |/ _ \    \___ \| | | | '_ \| |/ _ \/ __| __/ __|
// // | |_| | |_) |  __/ |_| |    | |  | |  __/     ___) | |_| | |_) | |  __/ (__| |_\__ \
// //  \___/|_.__/ \___|\__, |    |_|  |_|\___|    |____/ \__,_|_.__// |\___|\___|\__|___/
// //       ___  _      |___/          __  __          __        __|__/     _     _       
// //      / _ \| |__   ___ _   _     |  \/  | ___     \ \      / /__  _ __| | __| |      
// //     | | | | '_ \ / _ \ | | |    | |\/| |/ _ \     \ \ /\ / / _ \| '__| |/ _` |      
// //     | |_| | |_) |  __/ |_| |    | |  | |  __/      \ V  V / (_) | |  | | (_| |      
// //      \___/|_.__/ \___|\__, |    |_|  |_|\___|       \_/\_/ \___/|_|  |_|\__,_|      
// //                       |___/                                                         

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
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         vector<vector<int>> arr(n, vector<int>(m));
//         vector<int> v;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cin>>arr[i][j];
//                 v.push_back(arr[i][j]);
//             }
//         }
//         if(v.size()==1) cout<<-1<<endl;
//         else{
//             sort(v.begin(),v.end());
//             queue<int> q;
//             for(auto ele: v) q.push(ele);
//             vector<vector<int>> b(n, vector<int>(m));
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<m;j++){
//                     if(arr[i][j]==q.front()){
//                         int temp=q.front();
//                         q.pop();
//                         q.push(temp);
//                     }
//                     b[i][j] = q.front();
//                     q.pop();
//                 }
//             }
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<m;j++){
//                     cout<<b[i][j]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
        
//     }
// }
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                s.insert(a[i][j]);
            }
        }
        vector<int> ele(s.begin(), s.end());
        vector<vector<int>> b(n, vector<int>(m));
        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            for (int j = 0; j < m && possible; j++) {
                bool found = false;
                for (int k = 0; k < ele.size(); k++) {
                    if (ele[k] != a[i][j]) {
                        b[i][j] = ele[k];
                        ele.erase(ele.begin() + k);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    possible = false;
                }
            }
        }
        if (possible==false) {
            cout << -1 << endl;
        } 
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}
