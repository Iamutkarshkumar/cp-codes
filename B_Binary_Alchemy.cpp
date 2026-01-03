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
int main(){
     int N;
    cin >> N;

    // Initialize the matrix A of size N x N
    vector<vector<int>> A(N, vector<int>(N));

    // Read the matrix values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j]; // Fill the lower triangular part
            A[j][i] = A[i][j]; // Since A[i][j] == A[j][i]
        }
    }

    // Start with element 1 (which is element 0 in 0-based index)
    int current_element = 1; 

    // Combine current_element with 1, 2, ..., N in order
    for (int i = 1; i <= N; i++) {
        current_element = A[current_element - 1][i - 1]; // Combine current_element with i
    }

    // Output the final result
    cout << current_element << endl;

    return 0;
}