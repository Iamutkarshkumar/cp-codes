// #include <iostream>
// #include <string>
// using namespace std;

// bool canFormSubsequence(const string& s, const string& t) {
//     int n = s.length();
//     int m = t.length();
    
//     int j = 0; // Pointer for t
//     for (int i = 0; i < n; ++i) {
//         if (j < m && (s[i] == t[j] || s[i] == '?')) {
//             ++j; // Move to next character in t
//         }
//     }
//     return j == m;
// }

// void solve() {
//     string s, t;
//     cin >> s >> t;
    
//     int n = s.length();
//     int m = t.length();
    
//     // Check if it's possible to fit t into s
//     if (!canFormSubsequence(s, t)) {
//         cout << "NO" << endl;
//         return;
//     }

//     // Construct the result string
//     string result = s;
//     int j = 0; // Pointer for t
    
//     // Replace '?' with characters from t
//     for (int i = 0; i < n; ++i) {
//         if (j < m && result[i] == '?') {
//             result[i] = t[j++];
//         }
//     }
    
//     // Replace remaining '?' with 'a'
//     for (int i = 0; i < n; ++i) {
//         if (result[i] == '?') {
//             result[i] = 'a';
//         }
//     }
    
//     cout << "YES" << endl;
//     cout << result << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
    
//     return 0;
// }
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
        string s;cin>>s;
        string x; cin>>x;
        unordered_set<char> a;
        unordered_set<char> b;
        for(auto ele : s) a.insert(ele);
        for(auto ele : x) b.insert(ele);

        for(int i=0;i<x.length();i++){
            if(a.find(s[i])!=a.end()){
                a.remove(s[i]);
                b.remove(s[i]);
            }
        }
        
    }
}

