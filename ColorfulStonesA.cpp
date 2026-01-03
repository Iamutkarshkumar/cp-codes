#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    int i=0,j=0;
    while(j<=t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else if(s[i]!=t[j]){
            j++;
        }
    }
    cout<<i+1;
}