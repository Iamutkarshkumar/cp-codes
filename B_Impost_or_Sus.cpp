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
    int t; cin>>t;
    while(t--){
        string r; cin>>r;
        int n=r.size();
        for(char c:r) assert(c=='s'|| c=='u');
        int cntS=0;
        for(char c:r) if(c=='s') cntS++;
        if(cntS==0){
            cout<<(n/2+1)<<endl;
            continue;
        }
        int ans=0;
        int i=0;
        while(i<n && r[i]=='u') i++;
        ans+=(i+1)/2;
        int j=n-1;
        while(j>=0 && r[j]=='u') j--;
        ans+=(n-1-j+1)/2;
        int ucount=0;
        for(int k=i;k<=j;k++){
            if(r[k]=='u') ucount++;
            else{
                ans+=ucount/2;
                ucount=0;
            }
        }
        cout<<ans<<endl;
    }
 
}
