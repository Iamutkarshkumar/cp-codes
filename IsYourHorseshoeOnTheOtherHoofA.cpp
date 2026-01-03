#include <bits/stdc++.h>
using namespace std;
int main(){
    int s1,s2,s3,s4;
    int count =0;
    cin>>s1>>s2>>s3>>s4;
    vector<int> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    sort(v.begin(),v.end());
    for(int i=0; i<4;i++){
        if(v[i]==v[i+1]) count++;
    }
    cout<<count;
}

