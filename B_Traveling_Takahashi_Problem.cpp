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

double calculate_cost(long long x1, long long y1, long long x2, long long y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;cin >> N;

    vector<pair<long long, long long>> points(N);
  
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    // Calculate cost from origin to first point
    total_cost += calculate_cost(0, 0, points[0].first, points[0].second);

    // Calculate cost between consecutive points
    for (int i = 0; i < N - 1; i++) {
        total_cost += calculate_cost(points[i].first, points[i].second, 
                                     points[i+1].first, points[i+1].second);
    }

    // Calculate cost from last point back to origin
    total_cost += calculate_cost(points[N-1].first, points[N-1].second, 0, 0);

    // Output the result with appropriate precision
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}