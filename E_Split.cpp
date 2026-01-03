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
// int main(){
//     file_i_o();
//     int t;
//     cin>>t;
//     while(t--){
//         ll n,k;cin>>n>>k;
//         vector<ll> a(n);
//         for(int i=0;i<n;i++) cin>>a[i];
//         vector<ll> total(n+1,0);
//         for(auto v:a) total[v]++;
//         bool flag=true;

//         vector<ll> allowed(n+1,0);
//         for(int v=1;v<=n;v++){
//             if(total[v]%k){
//                 flag=false;
//                 break;
//             }
//             allowed[v]=total[v]/k;
//         }

//         if(not flag){
//             cout<<0<<endl;
//             continue;
//         }



//         vector<ll> freq(n+1,0);
//         ll ans=0;
//         ll l=0;
//         for(int r=0;r<n;r++){
//             freq[a[r]]++;
//             while(freq[a[r]]>allowed[a[r]]){
//                 freq[a[l]]--; 
//                 l++;
//             }
//             ans+=(r-l+1);
//         }
//         cout<<ans<<endl;
//     }
// }

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
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a; if(!(cin >> a)) return 0;
    while (a--) {
        ll b,c;cin>>b>>c;
        vector<ll> d(b);
        for (int i = 0; i < (int)b; ++i) cin >> d[i];

        vector<ll> e(b + 1, 0);    
        for (auto v : d) e[v]++;

        bool ok = true;
        vector<ll> f(b + 1, 0);     
        for (int v = 1; v <= (int)b; ++v) {
            if (e[v] % c != 0) { ok = false; break; }
            f[v] = e[v] / c;
        }

        if (!ok) {
            cout << 0 <<endl;
            continue;
        }

        vector<ll> g(b + 1, 0);          
        ll ans = 0;
        int l = 0;
        for (int r = 0; r < (int)b; ++r) {
            g[d[r]]++;
            while (g[d[r]] > f[d[r]]) {
                g[d[l]]--;
                ++l;
            }
            ans += (r - l + 1);
        }
        cout<<ans<<endl;
    }
}
