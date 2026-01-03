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

struct vector_hash {
    template <typename T>
    size_t operator () (const vector<T>& v) const {
        size_t hash_value = 0;
        for (const auto& e : v) {
            hash_value ^= hash<T>()(e) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        }
        return hash_value;
    }
};

vector<int> calculateRank(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({arr[i], i});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        result[vp[i].second] = i + 1;
    }
    return result;
}

vector<vector<int>> rem(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i) {
        vector<int> temp = arr;
        temp.erase(temp.begin() + i);
        result.push_back(temp);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        unordered_set<vector<int>, vector_hash> s;

        vector<vector<int>> v = rem(a);
        for (auto& ele : v) {
            s.insert(calculateRank(ele));
        }

        cout << s.size() << endl;
    }
    return 0;
}
