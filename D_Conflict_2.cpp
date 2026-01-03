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
struct Node {
    int parent;
    string s;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<Node> nodes;
    nodes.reserve(Q + 1);
    nodes.push_back({-1, ""});

    vector<int> pc(N+1);
    int server = 0;

    for(int i = 0; i < Q; i++){
        int type, p;
        cin >> type >> p;
        if(type == 1) {
            pc[p] = server;
        } else if(type == 2) {
            string seg;
            cin >> seg;
            nodes.push_back({pc[p], seg});
            pc[p] = nodes.size() - 1;
        } else {
            server = pc[p];
        }
    }

    vector<int> chain;
    for(int cur = server; cur; cur = nodes[cur].parent)
        chain.push_back(cur);

    size_t total = 0;
    for(int idx : chain) total += nodes[idx].s.size();

    string result;
    result.reserve(total);
    for(auto it = chain.rbegin(); it != chain.rend(); ++it)
        result += nodes[*it].s;

    cout << result;
    return 0;
}

