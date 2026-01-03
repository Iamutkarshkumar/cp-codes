//   ___  _                     __  __           ____        _     _           _       
//  / _ \| |__   ___ _   _     |  \/  | ___     / ___| _   _| |__ (_) ___  ___| |_ ___ 
// | | | | '_ \ / _ \ | | |    | |\/| |/ _ \    \___ \| | | | '_ \| |/ _ \/ __| __/ __|
// | |_| | |_) |  __/ |_| |    | |  | |  __/     ___) | |_| | |_) | |  __/ (__| |_\__ \
//  \___/|_.__/ \___|\__, |    |_|  |_|\___|    |____/ \__,_|_.__// |\___|\___|\__|___/
//       ___  _      |___/          __  __          __        __|__/     _     _       
//      / _ \| |__   ___ _   _     |  \/  | ___     \ \      / /__  _ __| | __| |      
//     | | | | '_ \ / _ \ | | |    | |\/| |/ _ \     \ \ /\ / / _ \| '__| |/ _` |      
//     | |_| | |_) |  __/ |_| |    | |  | |  __/      \ V  V / (_) | |  | | (_| |      
//      \___/|_.__/ \___|\__, |    |_|  |_|\___|       \_/\_/ \___/|_|  |_|\__,_|      
//                       |___/                                                         

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
// string getSubstring(const string& s, int l, int r) {
//     l--;
//     r--;
//     return s.substr(l, r - l + 1);
// }
// int help(const string& s1, const string& s2) {
//     vector<int> count(26, 0); 
//     for (char c : s1) {
//         count[c - 'a']++;
//     }
//     for (char c : s2) {
//         count[c - 'a']--;
//     }
//     int diffCount = 0;
//     for (int i = 0; i < 26; i++) {
//         diffCount += abs(count[i]);
//     }
//     return diffCount;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         string a,b;
//         cin>>a>>b;
//         int l,r;
//         for(int i=0;i<q;i++){
//             cin>>l>>r;
//             string x,y;
//             x=getSubstring(a,l,r);
//             y=getSubstring(b,l,r);
//             int count = help(x,y);
//             cout<<count/2<<endl;
//         }
//     }
// }



// string getSubstring(const string& s, int l, int r) {
//     l--;
//     r--;
//     return s.substr(l, r - l + 1);
// }
// int help(const string& s1, const string& s2) {
//     vector<int> count(26, 0); 
//     for (char c : s1) {
//         count[c - 'a']++;
//     }
//     for (char c : s2) {
//         count[c - 'a']--;
//     }
//     int diffCount = 0;
//     for (int i = 0; i < 26; i++) {
//         diffCount += abs(count[i]);
//     }
//     return diffCount;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         string a,b;
//         cin>>a>>b;
//         int l,r;
//         for(int i=0;i<q;i++){
//             cin>>l>>r;
//             string x,y;
//             x=getSubstring(a,l,r);
//             y=getSubstring(b,l,r);
//             // sort(x.begin(),x.end());
//             // sort(y.begin(),y.end());

//             int count = help(x,y);
//             cout<<count/2<<endl;
//             // if(x==y) cout<<0<<endl;
//             // else{
//             //     // int count=0;
//             //     // for(int i=0;i<x.length();i++){
//             //     //     if(x[i]!=y[i]) count++;
//             //     // }
//             //     // cout<<count<<endl;
//             //     int count = help(x,y);
//             //     cout<<count/2<<endl;
//             // }
//         }
//     }
// }


vector<vector<int>> helper(string& s) {
    int n = s.size();
    vector<vector<int>> pf(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pf[i][j] = pf[i - 1][j];
        }
        pf[i][s[i - 1] - 'a']++;
    }
    return pf;
}
vector<int> getFrequency(vector<vector<int>>& pf, int l, int r) {
    vector<int> freq(26, 0);
    for (int i = 0; i < 26; ++i) {
        freq[i] = pf[r][i] - pf[l - 1][i];
    }
    return freq;
}

int calDiff( vector<int>& freq1, vector<int>& freq2) {
    int diff = 0;
    for (int i = 0; i < 26; i++) {
        diff += abs(freq1[i] - freq2[i]);
    }
    return diff / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        auto x = helper(a);
        auto y = helper(b);

        while (q--) {
            int l, r;
            cin >> l >> r;

            auto freq_a = getFrequency(x, l, r);
            auto freq_b = getFrequency(y, l, r);

            int result = calDiff(freq_a, freq_b);
            cout << result << endl;
        }
    }
}