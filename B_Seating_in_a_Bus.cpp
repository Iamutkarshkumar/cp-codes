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
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        bool flag = true;
        for (int i = 0; i < n; i++) cin >> a[i];
        s.insert(a[0]);
        for (int i = 1; i < n; i++) {
            int seat = a[i];
            if (s.count(seat - 1) == 0 && s.count(seat + 1) == 0) {
                flag = false;
                break;
            }
            s.insert(seat);
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     set<int> occupied;

//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

    
//     occupied.insert(a[0]);

//     for(int i = 1; i < n; i++) {
//         int seat = a[i];
        
//         // Check if the current seat has at least one occupied neighboring seat
//         if(occupied.count(seat - 1) == 0 && occupied.count(seat + 1) == 0) {
//             cout << "NO" << endl;
//             return;
//         }
        
//         // If valid, mark this seat as occupied
//         occupied.insert(seat);
//     }

//     // If all checks passed, print "YES"
//     cout << "YES" << endl;
// }

// int main() {
//     int t;
//     cin >> t;

//     while(t--) {
//         solve();
//     }

//     return 0;
// }
