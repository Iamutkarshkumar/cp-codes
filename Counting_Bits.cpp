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
#include <bits/stdc++.h>
using namespace std;

void file_i_o(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    file_i_o();
    long long n;
    cin >> n;

    unordered_map<long long, int> cache; // optional: to avoid recomputation
    cache[0] = 0;

    long long sum = 0;
    for(long long i = 1; i <= n; ++i){
        // Use cache if i >> 1 was computed earlier
        int count = cache[i >> 1] + (i & 1);
        cache[i] = count;
        sum += count;
    }

    cout << sum << '\n';
}
