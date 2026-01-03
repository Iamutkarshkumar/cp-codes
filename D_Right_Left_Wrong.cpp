// ▀█▀    ─█▀▀█ ░█▀▄▀█    ─█▀▀█ ▀▀█▀▀ ░█▀▀▀█ ░█▀▄▀█ ▀█▀ ░█▀▀█ 
// ░█─    ░█▄▄█ ░█░█░█    ░█▄▄█ ─░█── ░█──░█ ░█░█░█ ░█─ ░█─── 
// ▄█▄    ░█─░█ ░█──░█    ░█─░█ ─░█── ░█▄▄▄█ ░█──░█ ▄█▄ ░█▄▄█
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int ans=0;
        string s;cin>>s;

        int lcount=0;
        int rcount=0;
        for(auto ele : s) if(ele=='L') lcount++;
        for(auto ele : s) if(ele=='R') rcount++;
// following logic is wrong 
//         if(lcount<=rcount){
//             int x=lcount;
//             while(x--){
//                 int l;
//                 int r;
//                 for(int i=0;i<n;i++){
//                     if(s[i]=='L'){
//                         l=i;
//                     } 
//                 } 
//                 for(int i=0;i<n;i++) if(s[i]=='R') r=i;
//                 s[l]='.';
//                 s[r]='.';
//                 for(int i=l;i<=r;i++) ans+=v[i];

//             }
//             cout<<ans<<endl;
//         }
//         else{
//             // while(rcount--){
//             //     int l;
//             //     int r;
//             //     for(int i=0;i<n;i++) if(s[i]=='L'){
//             //         l=i;
//             //         break;
//             //     } 
//             //     for(int i=0;i<n;i++) if(s[i]=='R'){
//             //         r=i;
//             //         break;
//             //     } 
//             //     s[l]='.';
//             //     s[r]='.';
//             //     for(int i=l;i<=r;i++) ans+=v[i];
//             // }
//             // cout<<ans<<endl;

//             int maxScore = 0;
//             int i = 0;
//             while (i < n) {
//                 if (s[i] == 'L') {
//                     int l = i;
//                     while (i < n && s[i] != 'R') {
//                         i++;
//                     }
//                     if (i < n && s[i] == 'R') {
//                         int segmentSum = 0;
//                         for (int j = l; j <= i; j++) {
//                             segmentSum += v[j];
//                         }
//                         maxScore += segmentSum;
//                     }
//                 }
//                 i++;
//             }
//             cout << maxScore << endl;
            
//         } 
//     }
// }
// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int main() {
// //     int t;
// //     cin >> t;

// //     while (t--) {
// //         int n;
// //         cin >> n;
// //         vector<int> a(n);
// //         string s;

// //         for (int i = 0; i < n; i++) {
// //             cin >> a[i];
// //         }
// //         cin >> s;

//         // int maxScore = 0;

//         // // Sliding window to find segments between 'L' and 'R'
//         // int i = 0;
//         // while (i < n) {
//         //     // Look for 'L'
//         //     if (s[i] == 'L') {
//         //         int l = i;
//         //         // Look for the first 'R' after 'L'
//         //         while (i < n && s[i] != 'R') {
//         //             i++;
//         //         }
//         //         if (i < n && s[i] == 'R') {
//         //             // Calculate sum from l to i (inclusive)
//         //             int segmentSum = 0;
//         //             for (int j = l; j <= i; j++) {
//         //                 segmentSum += a[j];
//         //             }
//         //             maxScore += segmentSum;
//         //         }
//         //     }
//         //     i++;
//         // }

//         // cout << maxScore << endl;
// //     }

// //     return 0;
// // }
