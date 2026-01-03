// █ █  █▀▄▀█ █  █ 　 █▀▀▄ █▀▀█ █▀▄▀█ █▀▀ 　  ▀  █▀▀ 　  █▀▀▀█ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ ▄ 　 █  █ █▀▀ 
//      █ █ █ █▄▄█ 　 █  █ █▄▄█ █ ▀ █ █▀▀ 　 ▀█▀ ▀▀█ 　  ▀▀▀▄▄ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█   　 █▀▀█ █▀▀ 
//      █   █ ▄▄▄█ 　 ▀  ▀ ▀  ▀ ▀   ▀ ▀▀▀ 　 ▀▀▀ ▀▀▀ 　  █▄▄▄█ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀ 　 ▀  ▀ ▀▀▀ 

// █   █ █  █ █▀▀█ 　 █   █  █ █▀▀█ █ █ █▀▀ 　  ▀  █▀▀▄ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ 
// █▄█▄█ █▀▀█ █  █ 　 █   █  █ █▄▄▀ █▀▄ ▀▀█ 　 ▀█▀ █  █ 　   █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//  ▀ ▀  ▀  ▀ ▀▀▀▀ 　 ▀▀▀ ▀▀▀▀ ▀ ▀▀ ▀ ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ 　   ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 

// ▀▀█▀▀ █▀▀█ 　 █  █ █  █ █▀▀▄ ▀▀█▀▀ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ █ █ 
//   █   █  █ 　 █▀▀█ █  █ █  █   █  　    █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//   ▀   ▀▀▀▀ 　 ▀  ▀ ▀▀▀▀ ▀  ▀   ▀ 　     ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 
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
    string s;cin>>s;
    string ans="";
    int i=0;
    while(i+1<s.length() or i<s.length()){
        if(s[i]=='-' and s[i+1]=='.'){ 
            ans.push_back('1');
            i+=2;
        }
        else if(s[i]=='-' and s[i+1]=='-') {
            ans.push_back('2');
            i+=2;
        }
        else {
            ans.push_back('0');
            i+=1;
        }
    }
    cout<<ans<<endl;
}