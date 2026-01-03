#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; if(!(cin>>N)) return 0;
    int first=-1,last=-1;
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        if(x==1){
            if(first==-1) first=i;
            last=i;
        }
    }
    cout << (first==-1 ? 0 : last-first) << '\n';
    return 0;
}
