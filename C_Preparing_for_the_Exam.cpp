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
//         int n,m,k;cin>>n>>m>>k;
//         vector<int> a(m);
//         for(int i=0;i<m;i++) cin>>a[i];
//         vector<int> q(k);
//         for(int i=0;i<k;i++) cin>>q[i];
//         string ans="";
//         int sum=0;
//         for(int i=1;i<=n;i++) sum+=i;
//         vector<int> help(m);
//         for(int i=0;i<m;i++) {
//             help[i]=sum-a[i];
//         }
//         int x=0;
//         for(auto ele: q) x+=ele;

//         if(q.size()==n){
//             for(int i=0;i<n;i++) ans.push_back('1');
//         }
//         else{
//             for(auto ele : help){
//                 if(ele==x) ans.push_back('1');
//                 else ans.push_back('0');
//             }
//         }
//         cout<<ans<<endl;


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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        vector<int> a(m);
        for(int i=0;i<m;i++) cin>>a[i];
        vector<int> q(k);
        unordered_set<int> help;
        for(int i=0;i<k;i++) {
            cin>>q[i];
            help.insert(q[i]);
        }
        string ans="";
        if(q.size()==n){
            for(int i=0;i<m;i++) ans.push_back('1');
        }
        else if(n-k>1){
            for(int i=0;i<m;i++) ans.push_back('0');
        }
        else{
            for(auto ele: a){
                auto it = help.find(ele);
                if (it != help.end()) {
                    ans.push_back('0');
                } 
                else {
                    ans.push_back('1');
                }
            }
        }
        cout<<ans<<endl;
    }
}
