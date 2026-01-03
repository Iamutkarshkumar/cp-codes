//   ___  _                     __  __           ____        _     _           _       
//  / _ \| |__   ___ _   _     |  \/  | ___     / ___| _   _| |__ (_) ___  ___| |_ ___ 
// | | | | '_ \ / _ \ | | |    | |\/| |/ _ \    \___ \| | | | '_ \| |/ _ \/ __| __/ __|
// | |_| | |_) |  __/ |_| |    | |  | |  __/     ___) | |_| | |_) | |  __/ (__| |_\__ \
//  \___/|_.__/ \___|\__, |    |_|  |_|\___|    |____/ \__,_|_.__// |\___|\___|\__|___/
//       ___  _      |___/          __  __          __        __|__/     _     _       
//      / _ \| |__   ___ _   _     |  \/  | ___     \ \      / /__  _ __| | __| |      
//     | | | | '_ \ / _ \ | | |    | |\/| |/ _ \     \ \ /\ / / _ \| '__| |/ _` |      
//     | |_| | |_) |  __/ |_| |    | |  | |  __/      \ V  V / (_) | |  | | (_| |      
//      \___/|_.__/ \___|\__, |    |_|  |_|\___|       \_/\_/ \___/|_|  |_|\__,_|    
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
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
typedef vector<int> vi;
typedef vector<pii> vpii;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    
    vector<vector<char>> v(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }

    string t;
    cin >> t;
    x--; 
    y--; 

    set<pii> visitedHouses;  
    int cnt = 0;
    if (v[x][y] == '@') {
        visitedHouses.insert({x, y});
        cnt++;
    }
    for (int i = 0; i < t.length(); i++) {
        int nx = x, ny = y;
        if (t[i] == 'U' && x > 0 && (v[x-1][y] == '.' || v[x-1][y] == '@')) {
            nx = x - 1;
        } 
        else if (t[i] == 'D' && x < h - 1 && (v[x+1][y] == '.' || v[x+1][y] == '@')) {
            nx = x + 1;
        } 
        else if (t[i] == 'L' && y > 0 && (v[x][y-1] == '.' || v[x][y-1] == '@')) {
            ny = y - 1;
        } 
        else if (t[i] == 'R' && y < w - 1 && (v[x][y+1] == '.' || v[x][y+1] == '@')) {
            ny = y + 1;
        }

      
        x = nx;
        y = ny;

      
        if (v[x][y] == '@' && visitedHouses.find({x, y}) == visitedHouses.end()) {
            visitedHouses.insert({x, y});
            cnt++;
        }
    }

    cout<<x+1<<" "<<y+1<<" "<<cnt<<endl; 
}
