#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int k = s.size();
    
    int j = 0;       // Pointer for s
    int i = 1;       // Position in the target string T (1-indexed)
    
    // Simulate the process of matching s as a subsequence in T
    while(j < k){
        char expected = (i % 2 == 1 ? 'i' : 'o');
        if(s[j] == expected)
            j++;
        i++;
    }
    
    // i - 1 is the length L0 of T that we needed to cover s
    int L = i - 1;
    
    // Ensure the final string T has even length
    if(L % 2 == 1)
        L++;
    
    // The answer is the number of characters we had to insert:
    // (Length of T) - (Length of s)
    cout << L - k << "\n";
    
    return 0;
}
