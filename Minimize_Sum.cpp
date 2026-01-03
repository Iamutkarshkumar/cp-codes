#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        ll sumA = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sumA += A[i];
        }

        vector<int> freq(M, 0);
        for (int x : A) ++freq[x];

        // suff[v] = number of elements >= v
        vector<int> suff(M+1, 0);
        for (int v = M-1; v >= 0; --v) suff[v] = suff[v+1] + freq[v];

        ll best = LLONG_MAX;
        for (int k = 0; k < M; ++k) {
            int t = M - k; // threshold: elements >= t will overflow
            ll cnt = (t <= M-1 ? suff[t] : 0); // if t==M => cnt=0
            ll cur = sumA + 1LL * N * k - 1LL * M * cnt;
            best = min(best, cur);
        }
        cout << best << '\n';
    }
    return 0;
}
