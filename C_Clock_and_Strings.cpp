// ▀█▀    ─█▀▀█ ░█▀▄▀█    ─█▀▀█ ▀▀█▀▀ ░█▀▀▀█ ░█▀▄▀█ ▀█▀ ░█▀▀█ 
// ░█─    ░█▄▄█ ░█░█░█    ░█▄▄█ ─░█── ░█──░█ ░█░█░█ ░█─ ░█─── 
// ▄█▄    ░█─░█ ░█──░█    ░█─░█ ─░█── ░█▄▄▄█ ░█──░█ ▄█▄ ░█▄▄█
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        if(min(a,b)==min(c,d) and max(a,b)==max(c,d)) cout<<"YES"<<endl;
        else{
            int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            int n = sizeof(v) / sizeof(v[0]);
            int x = -1, y = -1;

            for (int i = 0; i < n; i++) {
                if (v[i] == min(a,b)) x = i;
                if (v[i] == max(a,b)) y = i;
            }
            if (x == -1 || y == -1) {
                cout << "NO" << endl; 
                continue;
            }
            int count = 0;
            for (int i = x; i <= y; i++) {
                if (v[i] == c) count++;
                if (v[i] == d) count++;
            }
            if (count == 2 || count == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}
