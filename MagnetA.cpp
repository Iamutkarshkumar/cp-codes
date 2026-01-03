#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    int count=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0 ; i<v.size();i++){
        if(v[i]!=v[i+1]) {
            count++;
            
        }
    }
    cout<<count;
}



