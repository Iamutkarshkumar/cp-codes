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
// void file_i_o(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; if(!(cin>>t)) return 0;
//     while(t--){
//         int n; cin>>n;
//         vector<ll>a(n);
//         for(int i=0;i<n;i++) cin>>a[i];
//         ll s=0;
//         for(int i=0;i+1<n;i++) s+=llabs(a[i]-a[i+1]);
//         ll best = max(llabs(a[0]-a[1]), llabs(a[n-1]-a[n-2]));
//         for(int i=1;i+1<n;i++){
//             ll cur = llabs(a[i]-a[i-1]) + llabs(a[i]-a[i+1]) - llabs(a[i+1]-a[i-1]);
//             best = max(best, cur);
//         }
//         cout<<(s-best)<<endl;
//     }
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
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    file_i_o();
    int t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        if(n<=2){
            cout<<0<<endl;
            continue;
        }

        ll total=0;
        for(int i=0;i+1<n;i++)
            total+=llabs(v[i]-v[i+1]);

        ll best=0;
        best=max(best, llabs(v[0]-v[1]));
        best=max(best, llabs(v[n-1]-v[n-2]));

        for(int i=1;i+1<n;i++){
            ll gain = llabs(v[i]-v[i-1]) 
                    + llabs(v[i]-v[i+1]) 
                    - llabs(v[i+1]-v[i-1]);
            best=max(best, gain);
        }

        cout<<total-best<<endl;
    }
}
