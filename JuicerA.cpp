#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,b,d;
    int count=0;
    int sum=0;
    cin>>n>>b>>d;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a<=b){
            sum+=a;
            if(sum>d){
                count+=1;
                sum=0;
            }
        }
    }
    cout<<count;
}