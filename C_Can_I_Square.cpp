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
long long mySqrt(long long x) {
    long long l=0ll,h=x;
    while(l<=h){
        long long m=l+(h-l)/2ll;
        if(m*m==x) return m;
        else if(m*m>x) h=m-1ll;
        else l=m+1ll;
    }
    return h;
}
int main(){
    file_i_o();
    int t;
    cin>>t;
    while(t--){
        long long n;cin>>n;
        long long sum=0ll;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            sum+=x;
        }
        long long ans=mySqrt(sum);
        if(ans*ans==sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}