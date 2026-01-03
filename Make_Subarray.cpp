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
        string s;cin>>s;
        int i=-1,j=-1;
        for(int x=0;x<n;x++) if(s[x]=='1'){ i=x; break; }
        for(int x=n-1;x>=0;x--) if(s[x]=='1'){ j=x; break; }
        if(i==-1 || i==j){ cout<<0<<"\n"; continue; }
        int ans=0;
        for(int c=i+1;c<j;c++) if(s[c]=='0') ans++;
        cout<<ans<<"\n";
    }
    return 0;
}