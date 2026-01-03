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
        int N; cin>>N;
        int M = N*(N-1)/2;
        vector<long long> w(M);
        for(int i=0;i<M;i++) cin>>w[i];
        sort(w.begin(), w.end());
        int need = N-1;
        long long ans = 0;
        int selected = 0, p = 0;
        while(p < M && selected < need){
            int skipped = p - selected;
            long long E = 1LL*selected*(selected-1)/2; 
            int rem = M - p;
            int remNeed = need - selected;
            if(skipped < E && rem > remNeed){
                p++;
            } else {
                ans += w[p];
                selected++;
                p++;
            }
        }
        cout<<ans<<"\n";
    }
}