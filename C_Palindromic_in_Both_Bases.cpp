#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(ll x ,ll a){
    string k;
    while(x){
        k+=to_string(x%a);
        x/=a;
    }
    string re=k;
    reverse(re.begin(),re.end());
    if(k==re){
        return true;
    }
    else{
        return false;
    }
    
}
int main(void){
    ll A;
    ll N;
    cin>>A>>N;
    ll ans=0;
    
    for(ll i=0;i<1e6;i++){
        string s=to_string(i);
        string re=s;
        string k=s;;
        reverse(re.begin(),re.end());
        for(int i=1;i<s.size();i++){
            k+=re.at(i);
        }
        s=s+re;
        ll y=stoll(s);
        ll z=stoll(k);
        
        if(y<=N && check(y,A)){
            ans+=y;
        }
        if(z<=N && check(z,A)){
            ans+=z;
        }
    }
    cout<<ans;
}
