// // ▀█▀    ─█▀▀█ ░█▀▄▀█    ─█▀▀█ ▀▀█▀▀ ░█▀▀▀█ ░█▀▄▀█ ▀█▀ ░█▀▀█ 
// // ░█─    ░█▄▄█ ░█░█░█    ░█▄▄█ ─░█── ░█──░█ ░█░█░█ ░█─ ░█─── 
// // ▄█▄    ░█─░█ ░█──░█    ░█─░█ ─░█── ░█▄▄▄█ ░█──░█ ▄█▄ ░█▄▄█
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
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;cin>>n;
//         bool flag=false;
//         vector<int> v;
//         for(int i=0;i<n;i++){
//             int x;cin>>x;
//             v.push_back(x);
//         }
//         int e=0,o=0;
//         for(auto ele: v){
//             if(ele==1) flag=true;
//             if(ele%2==0) e++;
//             else o++;
//         }
//         if(e==n) cout<<0<<endl;
//         else if(o==n) cout<<0<<endl;
//         else if(flag==true) cout<<e<<endl;
//         else{
//             vector<int> od;
//             vector<int> ev;
//             for(auto ele: v){
//                 if(ele%2==0) ev.push_back(ele);
//                 else od.push_back(ele);
//             }
//             sort(ev.begin(),ev.end());
//             sort(od.begin(),od.end());
//             int count=0;
//             int x=od[od.size()-1];
//             for(int i=0;i<ev.size();i++){
//                 if(ev[i]<x) {
//                     x=max(x,ev[i]+x);
//                     count+=1;
                    
//                 }
//                 else {
//                     x=max(x,ev[i]+x);
//                     count+=2;
                   
//                 }
//             }
//             cout<<count<<endl;
//         }

//     }
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);

//         int evenCount = 0, oddCount = 0;

//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//             if (a[i] % 2 == 0) {
//                 ++evenCount;
//             } else {
//                 ++oddCount;
//             }
//         }
//         if(evenCount==n) cout<<0<<endl;
//         else if(oddCount==n) cout<<0<<endl;

//         // The minimum operations needed to make all numbers have the same parity
//         else cout <<  evenCount << endl;
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define all(x) x.begin(), x.end()
// #define mod 1000000007
// typedef vector<int> vi;

// vector<bool> checkGreaterOdd(const vector<int>& evens, const vector<int>& odds) {
//     vector<bool> result;
//     for (int even : evens) {
//         bool found = false;
//         for (int odd : odds) {
//             if (odd > even) {
//                 found = true;
//                 break;
//             }
//         }
//         result.push_back(found);
//     }
//     return result;
// }

// int main(){
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         bool hasOne = false;
//         int evenCount = 0, oddCount = 0;

//         for (int i = 0; i < n; i++) {
//             cin >> v[i];
//             if (v[i] == 1) hasOne = true;
//             if (v[i] % 2 == 0) evenCount++;
//             else oddCount++;
//         }

//         if (evenCount == n || oddCount == n) {
//             cout << 0 << endl;
//         } else if (hasOne) {
//             cout << evenCount << endl;
//         } else {
//             vector<int> evens, odds;
//             for (int i = 0; i < n; i++) {
//                 if (v[i] % 2 == 0) evens.pb(v[i]);
//                 else odds.pb(v[i]);
//             }

//             sort(all(evens));
//             sort(all(odds));

//             vector<bool> help = checkGreaterOdd(evens, odds);
//             int count = 0;
//             for (bool greaterFound : help) {
//                 count += (greaterFound ? 1 : 2);
//             }

//             cout << count << endl;
//         }
//     }
//     return 0;
// }


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
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         bool hasOne = false;
//         int evenCount = 0, oddCount = 0;

//         for (int i = 0; i < n; i++) {
//             cin >> v[i];
//             if (v[i] == 1) hasOne = true;
//             if (v[i] % 2 == 0) evenCount++;
//             else oddCount++;
//         }

//         if (evenCount == n || oddCount == n) {
//             cout << 0 << endl;
//         }
//         else if (hasOne) {
//             cout << evenCount << endl;
//         }
//         else {
//             vector<int> evens, odds;
//             for (int i = 0; i < n; i++) {
//                 if (v[i] % 2 == 0) evens.pb(v[i]);
//                 else odds.pb(v[i]);
//             }

//             sort(all(evens));
//             sort(all(odds));

//             int maxOdd = odds.back(); 
//             int count = 0;

//             for (int even : evens) {
//                 if (even < maxOdd) {
//                     count += 1;
//                     maxOdd=max(maxOdd,even+maxOdd);
//                 } 
//                 else {
//                     maxOdd=max(maxOdd,even+maxOdd);
//                     count += 2;
//                 }
//             }

//             cout << count << endl;
//         }
//     }
// }






#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll lo = 0; // largest odd number in a
    ll le = 0; // largest even number in a

    // Find largest odd and even numbers
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] > lo)
            lo = a[i];
        if (a[i] % 2 == 0 && a[i] > le)
            le = a[i];
    }

    int c = 0;
    bool all_same_parity = true;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity) {
        cout << 0 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] < lo) {
            c++;
            a[i] = a[i] + lo;
            lo = max(lo, a[i]);
        }
    }

    all_same_parity = true;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            all_same_parity = false;
            break;
        }
    }

    if (all_same_parity) {
        cout << c << "\n";
        return;
    }

    ll indx = 0; // index of largest odd
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && a[i] == lo) {
            indx = i;
            break;
        }
    }

    a[indx] = lo + le;
    c++;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            c++;
        }
    }

    cout << c << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}    




// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;cin>>n;
//         // bool flag=false;
//         vector<int> v;
//         for(int i=0;i<n;i++){
//             int x;cin>>x;
//             v.push_back(x);
//         }
//         int le=0,lo=0;
//         vector<int> od;
//         vector<int> ev;
//         for(auto ele: v){
//             if(ele%2==0) ev.push_back(ele);
//             else od.push_back(ele);
//         }
//         sort(ev.begin(),ev.end());
//         sort(od.begin(),od.end());

//         le=ev[ev.size()-1];
//         lo=od[od.size()-1];

//         int e=0,o=0;
//         for(auto ele: v){
//             // if(ele==1) flag=true;
//             if(ele%2==0) e++;
//             else o++;
//         }
//         if(e==n) cout<<0<<endl;
//         else if(o==n) cout<<0<<endl;
//         // else if(flag==true) cout<<e<<endl;
//         int count=0;
//         sort(v.begin(), v.end());
//         for (int i = 0; i < n; i++) {
//             if (v[i] % 2 == 0 && v[i] < lo) {
//                 count++;
//                 v[i] = v[i] + lo;
//                 lo = max(lo, v[i]);
//             }
//         }
//         bool all_same_parity = true;
//         for (int i = 1; i < n; i++) {
//             if (v[i] % 2 != v[0] % 2) {
//                 all_same_parity = false;
//                 break;
//             }
//         }

//         if (all_same_parity) {
//             cout << count << endl;
//         }

//         ll indx = 0; // index of largest odd
//         for (int i = 0; i < n; i++) {
//             if (v[i] % 2 == 1 && v[i] == lo) {
//                 indx = i;
//                 break;
//             }
//         }

//         v[indx] = lo + le;
//         count++;

//         for (int i = 0; i < n; i++) {
//             if (v[i] % 2 == 0) {
//                 count++;
//             }
//         }

//         cout << count << endl;
        

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
int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }

        ll max_odd = 0;  
        ll max_even = 0;  

 
        for (ll i = 0; i < n; i++) {
            if (v[i] % 2 == 1 && v[i] > max_odd)
                max_odd = v[i];
            if (v[i] % 2 == 0 && v[i] > max_even)
                max_even = v[i];
        }

        int count = 0;
        bool flag = true;
        for (ll i = 1; i < n; i++) {
            if (v[i] % 2 != v[0] % 2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 0 << endl;
            continue;
        }

        sort(v.begin(), v.end());

        for (ll i = 0; i < n; i++) {
            if (v[i] % 2 == 0 && v[i] < max_odd) {
                count++;
                v[i] += max_odd;
                max_odd = max(max_odd, v[i]);
            }
        }

        flag = true;
        for (ll i = 1; i < n; i++) {
            if (v[i] % 2 != v[0] % 2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << count << endl;
            continue;
        }

        ll index_of_max_odd = 0; 
        for (ll i = 0; i < n; i++) {
            if (v[i] % 2 == 1 && v[i] == max_odd) {
                index_of_max_odd = i;
                break;
            }
        }

        v[index_of_max_odd] += max_even;
        count++;

        for (ll i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                count++;
            }
        }

        cout << count << endl;
    }
}

