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
    int n;
    cin >> n;
    int one = 0;
    int two = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) one++;
        else two++;
    }

    if (one == 0) {  // Case when there are no 1s
        for (int i = 0; i < n; i++) cout << "2 ";
    } else if (two == 0) {  // Case when there are no 2s
        for (int i = 0; i < n; i++) cout << "1 ";
    } else {  // Case when both 1s and 2s are present
        cout << "2 1 ";
        for (int i = 0; i < two - 1; i++) cout << "2 ";
        for (int i = 0; i < one - 1; i++) cout << "1 ";
    }

    return 0;
}
