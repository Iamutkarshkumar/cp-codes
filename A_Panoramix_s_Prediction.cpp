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
vector<bool> sieveOfEratosthenes(int limit) {
    vector<bool> is_prime(limit+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p*p <= limit; ++p) {
        if (is_prime[p]) {
            for (int q = p*p; q <= limit; q += p)
                is_prime[q] = false;
        }
    }
    return is_prime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    auto is_prime = sieveOfEratosthenes(m);

    // 1) m itself must be prime
    if (!is_prime[m]) {
        cout << "NO\n";
        return 0;
    }

    // 2) there must be no prime strictly between n and m
    for (long long x = n+1; x < m; ++x) {
        if (is_prime[x]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}