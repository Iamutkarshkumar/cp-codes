// Chef and his family is trying to reach the airport. Including Chef, they are a total of 
// N
// N members.

// A single cab ride costs 
// max
// ⁡
// (
// 200
// ,
// 100
// ⋅
// X
// )
// max(200,100⋅X) rupees to transport 
// X
// X people from Chef's home to the airport. Further, a cab can fit at most 4 people.

// Chef may have to book multiple cabs in order for his entire family to reach the airport. What is the minimum cost for Chef's family to reach the airport if they take cabs optimally?
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
        int k=N/4, r=N%4;
        int ans=0;
        if(r==0) ans=k*400;
        else if(r==1){
            if(k>=1) ans=(k-1)*400 + 500; 
            else ans=200; 
        } else if(r==2) ans=k*400 + 200;
        else ans=k*400 + 300;
        cout<<ans<<"\n";
    }
}