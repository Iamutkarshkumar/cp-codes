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
    int t=1;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        unordered_set<int> s;
        int count=0;
        for(auto ele: v){
            if(ele==-1) count++;
            else s.insert(ele); 
        }
        if(s.size()+count!=n) cout<<"No"<<endl;
        else {
            cout<<"Yes"<<endl;
            vector<int> help;
            for(int i=1;i<=n;i++) {
                if(s.count(i)==0) help.push_back(i);
            }
            for(int i=0;i<n;i++){
                if(v[i]==-1) {
                    cout<<help.back()<<" ";
                    help.pop_back();
                }
                else cout<<v[i]<<" ";
            }
        }
    }
}