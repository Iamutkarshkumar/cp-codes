#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int N; string S; cin>>N>>S;
        int segs=0, len=0;
        for(int i=0;i<N;){
            if(S[i]=='0'){ i++; continue; }
            segs++;
            int j=i;
            while(j<N && S[j]=='1') j++;
            if(segs==1) len = j-i; 
            i=j;
        }
        if(segs==1 && (len==2 || len==3)) cout<<"No\n";
        else cout<<"Yes\n";
    }
}
