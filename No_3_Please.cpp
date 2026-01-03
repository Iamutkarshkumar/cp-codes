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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    cin >> T;
    while(T--){
        int N; 
        cin >> N;
        vector<int> A(N+1), S(N+1);
        for(int i = 1; i <= N; i++) 
            cin >> A[i];

        S[0] = 0;
        for(int i = 1; i <= N; i++)
            S[i] = (S[i-1] + A[i]) % 3;

        int r = 0;
        for(int i = 1; i <= N; i++)
            if(S[i] == 0) 
                r = i;

        if(r == 0){
            cout << "Yes\n";
            continue;
        }
        if(S[N] == 0){
            cout << "No\n";
            continue;
        }

        int first[3] = {-1, -1, -1};
        for(int t = 0; t <= N; t++){
            if(first[S[t]] < 0)
                first[S[t]] = t;
        }

        bool ok = false;
        for(int i = r + 1; i <= N; i++){
            int c = S[i];
            if(c != 0 && first[c] == i){
                ok = true;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }

}