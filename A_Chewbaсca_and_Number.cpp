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
//     // while(t--){
        
//     // }
//     string s= to_string(t);
//     string ans="";
//     for(int i=0;i<s.length();i++){
//         if(s[i]-'0'<4) ans.push_back(s[i]);
//         else{
//             int x= s[i]-'0';
//             x=9-x;
//             string l = to_string(s);
//             ans.push_back(l);
//         }
//     }
//     int w = stoi(ans);
//     cout<<w;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    string s = to_string(t);
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '4') {
            ans.push_back(s[i]);
        } 
        else {
            int x = s[i] - '0';
            x = 9 - x;
            ans.push_back(x + '0');
        }
    }

    long long w = stoi(ans);
    cout << w << endl;

    return 0;
}
