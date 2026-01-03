#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define sll signed long long 
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
ll count_triplets(ll n, ll x) {
    ll count = 0;

    // Iterate over possible values of a
    for (ll a = 1; a <= x; ++a) {
        // Iterate over possible values of b
        for (ll b = 1; b <= x - a; ++b) {
            // Calculate the maximum valid c
            // c must satisfy both conditions:
            // 1. a + b + c <= x
            // 2. ab + ac + bc <= n

            // Maximum c considering the sum constraint
            ll max_c_sum = x - a - b;
            
            // Maximum c considering the product constraint
            ll max_c_product = (n - a * b) / (a + b);
            
            // Valid c must satisfy both constraints
            ll max_c = min(max_c_sum, max_c_product);

            if (max_c >= 1) {
                count += max_c;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        cout << count_triplets(n, x) << endl;
    }
    return 0;
}