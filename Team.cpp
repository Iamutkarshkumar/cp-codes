#include<iostream>
using namespace std;
int main(){
    int n,x,y,z;
    int count_sol=0;
    cin>>n;
    //METHOD 1:
    for(int i=1; i<=n ; i++){
        int noo=0;
        for(int j=1 ;j<=3;j++){
            
            cin>>x;
            if(x==1) noo++;
        }
        if(noo>=2) count_sol++;
        
    }
    cout<<count_sol;

    //METHOD 2:
    for(int i=1 ; i<=n ; i++){
        cin>>x>>y>>z;
        if((x+y+z)>=2) count_sol++;
    }
    cout<<count_sol;
    
} 