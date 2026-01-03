#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> h;
    vector<int> a;
    int count=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        h.push_back(x);
        a.push_back(y);
    }
    for(int i=0;i<h.size();i++){
        for(int j=0;j<a.size();j++){
            if(h[i]==a[j]) count++;
        }
    }
    cout<<count;
}