#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        // string s;
        // cin>>s;
        // int lb=0;
        // int ub=0;
        // for(int i=0;i<n; i++){
        //     if(s[i]=='B'){
        //         lb=i;
        //         break;
        //     }
            
        // }
        // for(int i=0;i<n; i++){
        //     if(s[i]=='B') ub=i;
            
        // }
        // cout<<ub-lb+1<<endl;
        int n,m,k;
        cin>>n>>m>>k;
        int a[n];
        int b[m];
        int ans[k/2];
        cin>>n>>m>>k;
        for(int i=0; i<n ; i++){
            cin>>a[i];
        }
        for(int i=0; i<m ; i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        for(int i=0;i<(k/2); i++){
            ans[i]=b[i];
        }
        for(int i=k/2;i<=k;i++){
            for(int j=0;j<n; j++){
                for(int r=j; r<n ; r++){
                    if(ans[j]!=a[r]){
                        ans[i]=a[r];
                    }
                }
            }
        }
        for(int i=0; i<k; i++){
            cout<<ans[i]<<endl;
        }
    }
    
}