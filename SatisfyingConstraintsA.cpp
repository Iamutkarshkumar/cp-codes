// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     for(int i=0 ;i<t ; i++){
//         int n;
//         int count=0;
//         cin>>n;
//         for(int j=0 ; j<n; j++){
//             int a[n];
//             int x[n];
//             cin>>a[j];
//             cin>>x[j];
//         }
//         for(int j=0 ; j<n; j++){
//             int lb=0;
//             int ub=0;
//             if(a[j]==1){
                
//             }


//         }

//     }
// }


#include <bits/stdc++.h>
using namespace std;
int main() {
    int testCases;
    cin >> testCases;
    while(testCases--) {
        int constraints;
        cin >> constraints;
        int lowerBound = INT_MIN, upperBound = INT_MAX;
        vector<int> notEqualConstraints;
        while(constraints--) {
            int constraintType, constraintValue;
            cin >> constraintType >> constraintValue;
            if(constraintType == 1) lowerBound = max(lowerBound, constraintValue);
            else if(constraintType == 2) upperBound = min(upperBound, constraintValue);
            else notEqualConstraints.push_back(constraintValue);
        }
        sort(notEqualConstraints.begin(), notEqualConstraints.end());
        notEqualConstraints.erase(unique(notEqualConstraints.begin(), notEqualConstraints.end()), notEqualConstraints.end());
        int notEqualCount = 0;
        for(int notEqualValue : notEqualConstraints) {
            if(notEqualValue >= lowerBound && notEqualValue <= upperBound) {
                notEqualCount++;
            }
        }
        cout << max(0, upperBound - lowerBound + 1 - notEqualCount) << "\n";
    }
    return 0;
}










