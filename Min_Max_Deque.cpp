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
int compute_score(const vector<int>& a){
    int n = a.size();
    deque<int> dq;
    dq.push_back(a[0]);
    dq.push_back(a[1]);
    for(int i=2;i<n;i++){
        if(i%2==0){ // alice
            if(dq.front() < dq.back()) dq.push_front(a[i]);
            else dq.push_back(a[i]);
        } else { // bob
            if(dq.front() > dq.back()) dq.push_front(a[i]);
            else dq.push_back(a[i]);
        }
    }
    return min(dq.front(), dq.back());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<compute_score(a)<<" ";
        while(q--){
            int p,X;cin>>p>>X; p--;
            a[p]=X;
            cout<<compute_score(a)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


//GIVES TLE
//GIVES TLE
//GIVES TLE
//GIVES TLE
//GIVES TLE
//GIVES TLE
//GIVES TLE
//GIVES TLE