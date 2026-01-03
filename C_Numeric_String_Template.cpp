// // ▀█▀    ─█▀▀█ ░█▀▄▀█    ─█▀▀█ ▀▀█▀▀ ░█▀▀▀█ ░█▀▄▀█ ▀█▀ ░█▀▀█ 
// // ░█─    ░█▄▄█ ░█░█░█    ░█▄▄█ ─░█── ░█──░█ ░█░█░█ ░█─ ░█─── 
// // ▄█▄    ░█─░█ ░█──░█    ░█─░█ ─░█── ░█▄▄▄█ ░█──░█ ▄█▄ ░█▄▄█
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
//         int n;cin>>n;
//         vector<int> a(n);
//         for(int i=0;i<n;i++) cin>>a[i];

//         int m;cin>>m;
//         vector<string> v(m);
//         for(int i=0;i<m;i++) cin>>v[i];


        
//     }
// }

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
        
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
        
//         int m;
//         cin >> m;
        
//         while (m--) {
//             string s;
//             cin >> s;
            
//             unordered_map<int, char> num_to_char;
//             unordered_map<char, int> char_to_num;
//             bool valid = true;
            
//             for (int i = 0; i < n; i++) {
//                 int num = a[i];
//                 char ch = s[i];
                
//                 if (num_to_char.count(num)) {
//                     if (num_to_char[num] != ch) {
//                         valid = false;
//                         break;
//                     }
//                 } else {
//                     num_to_char[num] = ch;
//                 }
                
//                 if (char_to_num.count(ch)) {
//                     if (char_to_num[ch] != num) {
//                         valid = false;
//                         break;
//                     }
//                 } else {
//                     char_to_num[ch] = num;
//                 }
//             }
            
//             if (valid) {
//                 cout << "YES" << endl;
//             } else {
//                 cout << "NO" << endl;
//             }
//         }
//     }
    
//     return 0;
// }



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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m;cin >> m;
        while (m--) {
            string s;cin >> s;
            if (s.length() != n) {
                cout << "NO" << endl;
                continue;
            }
            unordered_map<int, char> nc;
            unordered_map<char, int> cn;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                int num = a[i];
                char ch = s[i];
                if (nc.count(num)) {
                    if (nc[num] != ch) {
                        flag = false;
                        break;
                    }
                } 
                else nc[num] = ch;
                if (cn.count(ch)) {
                    if (cn[ch] != num) {
                        flag = false;
                        break;
                    }
                } 
                else cn[ch] = num;
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
