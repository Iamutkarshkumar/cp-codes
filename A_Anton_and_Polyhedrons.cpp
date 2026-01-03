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
int main(){
    file_i_o();
    
    // Tetrahedron. Tetrahedron has 4 triangular faces.
    // Cube. Cube has 6 square faces.
    // Octahedron. Octahedron has 8 triangular faces.
    // Dodecahedron. Dodecahedron has 12 pentagonal faces.
    // Icosahedron. Icosahedron has 20 triangular faces. 

    unordered_map<string, int> polyhedron_faces = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };
    int n, total_faces = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string polyhedron;
        cin >> polyhedron;
        total_faces += polyhedron_faces[polyhedron];
    }
    cout << total_faces << endl;
    return 0;

    
}