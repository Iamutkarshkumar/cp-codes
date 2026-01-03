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

const ll NEG_INF = (ll)-9e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; ll K;
        cin >> N >> K;
        vector<ll> W(N+1);
        vector<int> C(N+1);
        int maxColor = 0;
        for (int i = 1; i <= N; ++i) cin >> W[i];
        for (int i = 1; i <= N; ++i) {
            cin >> C[i];
            maxColor = max(maxColor, C[i]);
        }

        // base[col] holds the "base" such that true_best[col] = base[col] + offset
        vector<ll> base(maxColor + 1, NEG_INF);
        base[0] = 0;            // start at city 1 with color 0 and 0 coins
        ll max_base = 0;       // max over base[*]
        ll offset = 0;         // lazy offset applied to all true_best

        // process moves from city i to city i+1 for i = 1..N-1
        for (int i = 1; i < N; ++i) {
            int col = C[i+1];
            ll w = W[i+1];

            // candidate if we change to 'col' before entering: (best overall) - K
            ll candidate = max_base - K;

            // update base[col] by considering switching vs staying
            // then add the +2*w for the colored city (others effectively get -w via offset)
            base[col] = max(base[col], candidate) + 2LL * w;

            // apply -w to everyone via offset
            offset -= w;

            // update global maximum base (only base[col] changed)
            if (base[col] > max_base) max_base = base[col];
        }

        ll answer = max_base + offset;
        cout << answer << '\n';
    }
    return 0;
}