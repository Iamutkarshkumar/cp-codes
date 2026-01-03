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
int main(){
    int a,b,c;
    vector<int> arr;
    vector<int> brr;
    cin>>a>>b>>c;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    brr.push_back(a);
    brr.push_back(b);
    brr.push_back(c);
    sort(arr.begin(),arr.end());
    for(auto ele: arr) cout<<ele<<endl;
    cout<<endl;
    for(auto ele: brr) cout<<ele<<endl;
}