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
    ll n;cin>>n;
    ll x=(n*(n+1))/2;
    if(x%2==1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        vi a,b;
        ll sum1=0,sum2=0;
        for(int i=n;i>=1;i--){
            if(sum1<=sum2){
                a.pb(i);
                sum1+=i;
            }
            else{
                b.pb(i);
                sum2+=i;
            }
        }
        cout<<a.size()<<"\n";
        for(auto i:a) cout<<i<<" ";
        cout<<"\n"<<b.size()<<"\n";
        for(auto i:b) cout<<i<<" ";
    }
}