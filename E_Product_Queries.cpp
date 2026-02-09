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
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        const int INF=1e9;
        vector<int> dp(n+1,INF);
        bool flag=false;
        for(auto x:a) if(x==1) flag=true;
        dp[1]=0;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        for(int x:a){
            if(x==1) continue;
            for(int j=1;j*x<=n;j++){
                if(dp[j]!=INF){
                    dp[j*x]=min(dp[j*x],dp[j]+1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(i==1) cout<<(flag?1:-1)<<" ";
            else if(dp[i]==INF) cout<<-1<<" ";
            else cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
}