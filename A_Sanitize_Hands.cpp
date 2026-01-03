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
    int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        
        // Calculate cumulative sum
        vector<int> help(n);
        help[0] = v[0];
        for(int i = 1; i < n; i++) {
            help[i] = help[i-1] + v[i];
        }

        // Find the smallest index i such that the cumulative sum > m
        int i = 0;
        while(i < n && help[i] <= m) {
            i++;
        }

        // Output the result: 1-based index
        cout << i  << endl;
    
}