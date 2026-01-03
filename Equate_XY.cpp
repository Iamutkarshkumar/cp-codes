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

    int T; cin>>T;
    while(T--){
        ll X,Y,Z,C; cin>>X>>Y>>Z>>C;
        if(X==Y){
            cout<<0<<"\n";
            continue;
        }
        ll ans = 2*C; 
        if(X%Y==0){
            ll Q = X/Y;
            for(ll i=1;i*i<=Q;i++){
                if(Q%i==0){
                    ll d1=i,d2=Q/i;
                    ll L1=Y*d1, L2=Y*d2;
                    ans = min(ans, abs(Z-L1)+C);
                    if(d1!=d2) ans = min(ans,abs(Z-L2)+C);
                }
            }
        }
        else if(Y%X==0){
            ll Q = Y/X;
            for(ll i=1;i*i<=Q;i++){
                if(Q%i==0){
                    ll d1=i, d2=Q/i;
                    ll L1=X*d1, L2=X*d2;
                    ans = min(ans, abs(Z-L1)+C);
                    if(d1!=d2) ans = min(ans, abs(Z-L2)+C);
                }
            }
        }
        cout<<ans<<endl;
    }
}