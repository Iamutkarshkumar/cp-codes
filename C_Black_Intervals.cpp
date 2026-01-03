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
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<char> painted(N+2, 0);
    int intervals = 0;

    while (Q--) {
        int x;
        cin >> x;
        bool leftBlack  = painted[x - 1];
        bool rightBlack = painted[x + 1];

        if (painted[x] == 0) {
            if (!leftBlack && !rightBlack) {
                intervals += 1;
            } else if (leftBlack && rightBlack) {
                intervals -= 1;
            }
            painted[x] = 1;
        } else {
            if (!leftBlack && !rightBlack) {
                intervals -= 1;
            } else if (leftBlack && rightBlack) {
                intervals += 1;
            }
            painted[x] = 0;
        }

        cout << intervals << "\n";
    }

    return 0;
}
