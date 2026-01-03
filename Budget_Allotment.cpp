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
// int countAtleast(vector<int>& arr, int x) {
//     int count = 0;
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] >= x) count++;
//     }
//     return count;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, x;
//         cin >> n >> x;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         ll extra = 0;
//         ll req = 0;
//         for (int i = 0; i < n; i++) {
//             if (arr[i] < x) req += x - arr[i];
//             if (arr[i] > x) extra += arr[i] - x;
//         }

//         if (extra >= req) {
//             cout << n << endl;
//         } 
//         else {
//             for (int i = 0; i < n; i++) {
//                 if (arr[i] < x) {
//                     if (x - arr[i] <= extra) {
//                         extra -= (x - arr[i]);
//                         arr[i] = x; 
//                     }
//                 }
//             }
//             cout << countAtleast(arr, x) << endl;

           
//         }
//     }
//     return 0;
// }
// int countAtleast(vector<int>& arr, int x) {
//     int count = 0;
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] >= x) count++;
//     }
//     return count;
// }

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n, x;
//         cin >> n >> x;
//         vector<int> arr(n);
        
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
        
//         long long extra = 0;
//         long long req = 0;
        
//         for (int i = 0; i < n; i++) {
//             if (arr[i] < x) {
//                 req += x - arr[i];
//             } 
//             else if (arr[i] > x) {
//                 extra += arr[i] - x;
//             }
//         }
        
//         if (extra >= req) {
//             cout << n << endl;
//         } 
//         else {
            
//             sort(arr.begin(), arr.end());
            
//             int count = 0;
//             long long current_extra = extra;
            
//             for (int i = 0; i < n; i++) {
//                 if (arr[i] < x) {
//                     if (x - arr[i] <= current_extra) {
//                         current_extra -= (x - arr[i]);
//                         count++;
//                     } 
//                     // else {
//                     //     break;
//                     // }
//                 }
//             }
            
//             cout << countAtleast(arr, x) + count << endl;
//         }
//     }
    
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int countAtleast(const vector<int>& arr, int x) {
    int count = 0;
    for (int value : arr) {
        if (value >= x) count++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        
        ll extra = 0;
        ll req = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] < x) req += x - arr[i];
            if (arr[i] > x) extra += arr[i] - x;
        }
        
        if (extra >= req) {
            cout << n << '\n';
        } else {
            // Update sectors with excess budget to meet the requirement
            for (int i = 0; i < n; ++i) {
                if (arr[i] < x) {
                    if (x - arr[i] <= extra) {
                        extra -= (x - arr[i]);
                        arr[i] = x; 
                    }
                }
            }
            cout << countAtleast(arr, x) << '\n';
        }
    }
    
    return 0;
}
