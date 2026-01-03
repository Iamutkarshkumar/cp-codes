#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, const vector<int>& A) {
    for (int a : A) {
        if ((x ^ a) >= a) {
            return false; // Condition fails for this a
        }
    }
    return true; // Condition holds for all a
}

int countValidX(int N, const vector<int>& A) {
    int maxA = *max_element(A.begin(), A.end());
    int count = 0;

    // Check for all possible values of X from 1 to maxA - 1
    for (int x = 1; x < maxA; ++x) {
        if (isValid(x, A)) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // Get the result for the current test case
        int result = countValidX(N, A);
        cout << result << '\n';
    }
    
    return 0;
}
