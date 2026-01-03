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
static bool cmp(int a,int b,int n){
    if(__gcd(a,n)>__gcd(b,n)) {
        return a>b;
    }
}
int main(){
    file_i_o();
    
    int t;
    cin>>t;
    while(t--){
        int N;cin>>N;
        vector<int> v(N);
        for(int i=1;i<=N;i++) v[i-1]=i;
        sort(v.begin(),v.end(),[N](int a,int b){
            int ga=__gcd(a,N), gb=__gcd(b,N);
            if(ga!=gb) return ga>gb; 
            return a< b;           
        });
        for(auto x:v) cout<<x<<" ";
        cout<<"\n";
    }
}