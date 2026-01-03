#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   for(int i=0; i<=n; i++){
    string s;
    cin>>s;
    int length=s.size();
    int count=0;
    if(length>10){
        cout<<s[0]<<length-2<<s[length-1];
        cout<<endl;
    }
    else cout<<s<<endl;
   }
}
