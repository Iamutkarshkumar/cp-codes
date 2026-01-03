// #include <bits/stdc++.h>
// using namespace std;
// #define gc getchar_unlocked
// #define fo(i, n) for (i = 0; i < n; i++)
// #define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
// #define ll long long
// #define deb(x) cout << #x << "=" << x << endl
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
// #define all(x) x.begin(), x.end()
// #define clr(x) memset(x, false, sizeof(x))
// #define sortall(x) sort(all(x))
// #define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
// #define PI 3.1415926535897932384626
// #define mod 1000000007
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpii;
// typedef vector<pl> vpl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// bool isPrime(int num) {
//     if (num <= 1) return false;
//     for (int i = 2; i <= sqrt(num); i++) {
//         if (num % i == 0) {
//             return false;  
//         }
//     } 
//     return true;  
// }
// void solve(){
//     int n;cin>>n;
//         vector<int> v(n);
//         for(int i=0;i<n;i++) cin>>v[i];
//         bool flag=false;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(isPrime(v[i]+v[j])==false){
//                     cout<<i+1<<" "<<j+1<<endl;
//                     flag=true;
//                     return;
//                 }
//             }
//         }
//         if(flag==false) cout<<-1<<endl;
        
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
        
//         solve();

//     }
// }

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
const int MAX_SUM = 200;
vector<bool> sieve(int max_val) {
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i * i <= max_val; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_val; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
pair<int, int> helper(const vector<int>& arr, const vector<bool>& is_prime) {
    unordered_map<int, int> value_index;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (auto it = value_index.begin(); it != value_index.end(); ++it) {
            int num = it->first;
            int index = it->second;
            if (!is_prime[arr[i] + num]) {
                return {index + 1, i + 1}; 
            }
        }
        value_index[arr[i]] = i;
    }
    return {-1, -1}; 
}
int main() {
    vector<bool> is_prime = sieve(MAX_SUM);
    int T;cin >> T;
    while (T--) {
        int N;cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];
        auto result = helper(arr, is_prime);
        if (result.first == -1) cout << -1 << endl;
        else cout << result.first << " " << result.second << endl;
    }
}
