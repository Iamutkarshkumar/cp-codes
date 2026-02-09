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
        int n;cin>>n;
        vector<ll>a(n);for(int i=0;i<n;i++)cin>>a[i];
        vector<int>b(n);for(int i=0;i<n;i++)cin>>b[i];
        vector<ll>pref(n);pref[0]=b[0];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+b[i];
        sort(a.begin(),a.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            if(i>0 && a[i]==a[i-1]) continue;
            ll x=a[i];
            int usable=n-i;
            int k=upper_bound(pref.begin(),pref.end(),usable)-pref.begin();
            ans=max(ans,x*(ll)k);
        }
        cout<<ans<<endl;
    }
}
