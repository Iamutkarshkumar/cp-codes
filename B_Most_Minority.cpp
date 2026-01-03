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
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    if(!(cin>>N>>M)) return 0;
    vector<string> s(N);
    for(int i=0;i<N;i++) cin>>s[i];
    vector<int> score(N,0);
    for(int j=0;j<M;j++){
        int ones=0;
        for(int i=0;i<N;i++) if(s[i][j]=='1') ones++;
        int zeros = N - ones;
        if(ones==0 || zeros==0){
            for(int i=0;i<N;i++) score[i]++;
        } else if(zeros < ones){
            for(int i=0;i<N;i++) if(s[i][j]=='0') score[i]++;
        } else {
            for(int i=0;i<N;i++) if(s[i][j]=='1') score[i]++;
        }
    }
    int mx = *max_element(score.begin(), score.end());
    bool first=true;
    for(int i=0;i<N;i++){
        if(score[i]==mx){
            if(!first) cout<<' ';
            cout<<i+1;
            first=false;
        }
    }
    cout<<endl;
}
