#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; string s; cin>>n>>s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(s == rs){
            cout<<0<<"\n\n";
            continue;
        }
        vector<int> pos;
        for(int i=0;i<n;i++) if(s[i]=='0') pos.push_back(i+1);
        if(pos.empty()){
            // no zeros -> take all ones (every char is '1')
            cout<<n<<"\n";
            for(int i=1;i<=n;i++) cout<<i<<(i==n?'\n':' ');
            cout<<"\n";
        } else {
            cout<<pos.size()<<"\n";
            for(size_t i=0;i<pos.size();i++){
                cout<<pos[i]<<(i+1==pos.size()?'\n':' ');
            }
        }
    }
    return 0;
}
