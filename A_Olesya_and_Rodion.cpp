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
int countDigits(int number) {
    if (number == 0) return 1; 
    return static_cast<int>(log10(abs(number)) + 1);
}
int main(){
    long long n,t;cin>>n>>t;
    string s="";
    if(countDigits(t)>n) cout<<-1;
    else if(t<10) for(int i=0;i<n;i++) cout<<t;  
    else {
		for (int i = 0; i < n - 1; i++) {
			cout << 1;
		}cout << 0;
	}
}