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
bool areConsecutiveHealthy(int i, int k, const string& s) {
    for (int j = i; j < i + k; ++j) {
        if (s[j] == 'X') return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int maxStrawberries = 0;
    for (int i = 0; i <= n - k; ++i) {
        if (areConsecutiveHealthy(i, k, s)) {
            maxStrawberries++;
            // Mark these K teeth as cavities (turn them into 'X')
            for (int j = i; j < i + k; ++j) {
                s[j] = 'X';
            }
        }
    }

    cout << maxStrawberries << endl;
    return 0;
}