#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0 ;i<t ; i++){ 
        vector<int> v;
        for(int j=0; j<4; j++){
            int x,y;
            cin>>x>>y;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout<<(v[2]-v[1])*(v[2]-v[1])<<endl;
    }
}