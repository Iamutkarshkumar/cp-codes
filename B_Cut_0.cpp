
// █ █  █▀▄▀█ █  █ 　 █▀▀▄ █▀▀█ █▀▄▀█ █▀▀ 　  ▀  █▀▀ 　  █▀▀▀█ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ ▄ 　 █  █ █▀▀ 
//      █ █ █ █▄▄█ 　 █  █ █▄▄█ █ ▀ █ █▀▀ 　 ▀█▀ ▀▀█ 　  ▀▀▀▄▄ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█   　 █▀▀█ █▀▀ 
//      █   █ ▄▄▄█ 　 ▀  ▀ ▀  ▀ ▀   ▀ ▀▀▀ 　 ▀▀▀ ▀▀▀ 　  █▄▄▄█ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀ 　 ▀  ▀ ▀▀▀ 

// █   █ █  █ █▀▀█ 　 █   █  █ █▀▀█ █ █ █▀▀ 　  ▀  █▀▀▄ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ 
// █▄█▄█ █▀▀█ █  █ 　 █   █  █ █▄▄▀ █▀▄ ▀▀█ 　 ▀█▀ █  █ 　   █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//  ▀ ▀  ▀  ▀ ▀▀▀▀ 　 ▀▀▀ ▀▀▀▀ ▀ ▀▀ ▀ ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ 　   ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 

// ▀▀█▀▀ █▀▀█ 　 █  █ █  █ █▀▀▄ ▀▀█▀▀ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ █ █ 
//   █   █  █ 　 █▀▀█ █  █ █  █   █  　    █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//   ▀   ▀▀▀▀ 　 ▀  ▀ ▀▀▀▀ ▀  ▀   ▀ 　     ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 
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
// int main() {
//     double X;cin >> X;
//     string help = to_string(X);
//     // result.erase(result.find_last_not_of('0') + 1, string::npos); 
//     // if (result.back() == '.') {
//     //     result.pop_back(); 
//     // }
//     // cout << result << endl;

//     string ans="";
//     int i=0;
//     while(help[i]!='.'){
//         ans.push_back(help[i]);
//         i++;
//     }
//     int j=help.size()-1;
//     while(help[j]=='0') j--;
//     for(int k=i;k<=j;k++) ans.push_back(help[k]);
//     else cout<<ans<<endl;

// }
int main() {
    double X;cin >> X;
    string help = to_string(X);
    string ans = "";
    int i = 0;
    while (help[i] != '.') {
        ans.push_back(help[i]);
        i++;
    }
    ans.push_back(help[i]);
    i++;
    int j = help.size() - 1;
    while (help[j] == '0') j--;
    for (int k = i; k <= j; k++) ans.push_back(help[k]);
    if (ans.back() == '.') ans.pop_back();
    cout << ans << endl;
}