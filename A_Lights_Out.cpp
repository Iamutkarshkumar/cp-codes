// █ █  █▀▄▀█ █  █ 　 █▀▀▄ █▀▀█ █▀▄▀█ █▀▀ 　  ▀  █▀▀ 　  █▀▀▀█ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ ▄ 　 █  █ █▀▀ 
//      █ █ █ █▄▄█ 　 █  █ █▄▄█ █ ▀ █ █▀▀ 　 ▀█▀ ▀▀█ 　  ▀▀▀▄▄ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█   　 █▀▀█ █▀▀ 
//      █   █ ▄▄▄█ 　 ▀  ▀ ▀  ▀ ▀   ▀ ▀▀▀ 　 ▀▀▀ ▀▀▀ 　  █▄▄▄█ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀ 　 ▀  ▀ ▀▀▀ 

// █   █ █  █ █▀▀█ 　 █   █  █ █▀▀█ █ █ █▀▀ 　  ▀  █▀▀▄ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ 
// █▄█▄█ █▀▀█ █  █ 　 █   █  █ █▄▄▀ █▀▄ ▀▀█ 　 ▀█▀ █  █ 　   █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//  ▀ ▀  ▀  ▀ ▀▀▀▀ 　 ▀▀▀ ▀▀▀▀ ▀ ▀▀ ▀ ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ 　   ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 

// ▀▀█▀▀ █▀▀█ 　 █  █ █  █ █▀▀▄ ▀▀█▀▀ 　 ▀▀█▀▀ █  █ █▀▀ 　 █▀▀ █  █ █▀▀█ █▀▀▄ █▀▀█ █   █ █▀▀ █ █ 
//   █   █  █ 　 █▀▀█ █  █ █  █   █  　    █   █▀▀█ █▀▀ 　 ▀▀█ █▀▀█ █▄▄█ █  █ █  █ █▄█▄█ ▀▀█ 
//   ▀   ▀▀▀▀ 　 ▀  ▀ ▀▀▀▀ ▀  ▀   ▀ 　     ▀   ▀  ▀ ▀▀▀ 　 ▀▀▀ ▀  ▀ ▀  ▀ ▀▀▀  ▀▀▀▀  ▀ ▀  ▀▀▀ 
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
    int grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }
    int result[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] % 2 != 0) {  
                result[i][j] = 1 - result[i][j];


                if (i > 0) result[i-1][j] = 1 - result[i-1][j]; 
                if (i < 2) result[i+1][j] = 1 - result[i+1][j]; 
                if (j > 0) result[i][j-1] = 1 - result[i][j-1];  
                if (j < 2) result[i][j+1] = 1 - result[i][j+1];  
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

}
