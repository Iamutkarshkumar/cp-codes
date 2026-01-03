// //   ___  _                     __  __           ____        _     _           _       
// //  / _ \| |__   ___ _   _     |  \/  | ___     / ___| _   _| |__ (_) ___  ___| |_ ___ 
// // | | | | '_ \ / _ \ | | |    | |\/| |/ _ \    \___ \| | | | '_ \| |/ _ \/ __| __/ __|
// // | |_| | |_) |  __/ |_| |    | |  | |  __/     ___) | |_| | |_) | |  __/ (__| |_\__ \
// //  \___/|_.__/ \___|\__, |    |_|  |_|\___|    |____/ \__,_|_.__// |\___|\___|\__|___/
// //       ___  _      |___/          __  __          __        __|__/     _     _       
// //      / _ \| |__   ___ _   _     |  \/  | ___     \ \      / /__  _ __| | __| |      
// //     | | | | '_ \ / _ \ | | |    | |\/| |/ _ \     \ \ /\ / / _ \| '__| |/ _` |      
// //     | |_| | |_) |  __/ |_| |    | |  | |  __/      \ V  V / (_) | |  | | (_| |      
// //      \___/|_.__/ \___|\__, |    |_|  |_|\___|       \_/\_/ \___/|_|  |_|\__,_|      
// //                       |___/                                                         

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
//         int n;cin>>n;
//         string s;cin>>s;
//         unordered_map<char, int> mp;
//         for (auto ele : s) mp[ele]++;
//         vector<pair<int, char>> v;
//         for (auto ele : mp) v.push_back({ele.second, ele.first});
//         sort(v.rbegin(), v.rend());
//         string ans;
//         for (auto ele : v) ans.append(ele.first, ele.second);
//         cout<<ans<<endl;
//     }
// }


// cba
// dddfe
// tturle
// pppppppp
// ooeeccsrfd


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Frequency map to count occurrences of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Vector to store characters and their frequencies
        vector<pair<int, char>> freq_vec;
        for (const auto& entry : freq) {
            freq_vec.push_back({entry.second, entry.first});
        }

        // Sort characters by frequency in descending order
        sort(freq_vec.rbegin(), freq_vec.rend());

        // Construct the result string
        string result;
        vector<pair<int, char>> blocks;

        // Generate blocks of characters
        for (const auto& p : freq_vec) {
            blocks.push_back(p);
        }

        // Create a result string with blocks of characters
        while (!blocks.empty()) {
            vector<pair<int, char>> next_blocks;
            for (auto& b : blocks) {
                result += b.second;
                if (--b.first > 0) {
                    next_blocks.push_back(b);
                }
            }
            blocks = next_blocks;
        }

        cout << result << endl;
    }

    return 0;
}
