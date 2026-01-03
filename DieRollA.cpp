#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,w,a;
    cin>>y>>w;
    a=(max(y,w));
    if(a==1) cout<<1<<"/"<<1;
    else if(a==3) cout<<2<<"/"<<3;
    else if(a==4) cout<<1<<"/"<<2;
    else if(a==5) cout<<1<<"/"<<3;
    else cout<<(6-max(y,w))+1<<"/"<<6;
}