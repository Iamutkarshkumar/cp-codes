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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        vector<int> odd, even;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }
        sort(begin(odd), end(odd), greater<int>());
        sort(begin(even), end(even), greater<int>());
        if(odd.size()==0){
            for(int i=0;i<n;i++) cout<<0<<" ";
            cout<<endl;
        }
        else if(even.size()==0){
            vector<ll> ans(n,0);
            for(int i=0;i<n;i+=2) ans[i]=odd[0];
            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else{
            vector<ll> ans(n,0);
            int x=0;
            ans[x]=odd[0];
            x++;
            ll sum = odd[0];
            // add all evens (even[0] is largest because sorted desc)
            for(int i=0;i<(int)even.size();i++){
                sum += even[i];
                ans[x] = sum;
                x++;
            }
            // a = full sum (odd + all evens), b = a - smallest_even (since even is desc, smallest is back())
            ll a_full = ans[x-1];
            ll b_prev = ans[x-2];

            int remaining = n - x; // number of positions left to fill
            if(remaining > 0){
                bool oddCountIsOdd = (odd.size() % 2 == 1);
                // pattern after evens: b, a, b, a, ...
                // idx = 0 => first position after evens => b
                for(int idx = 0; idx < remaining; ++idx){
                    int pos = x + idx;
                    if(oddCountIsOdd){
                        if(idx % 2 == 0) ans[pos] = b_prev;
                        else ans[pos] = a_full;
                    } else {
                        // when odd count is even, the very last k must be 0
                        if(pos == n-1){
                            ans[pos] = 0;
                        } else {
                            if(idx % 2 == 0) ans[pos] = b_prev;
                            else ans[pos] = a_full;
                        }
                    }
                }
            }

            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
}