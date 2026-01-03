#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count1=0;
    int count2=0;
    int count3=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
        if(t==1) count1++;
        else if(t==2) count2++;
        else count3++;
    }
    bool flag=false;
    int a=min(count1,count2);
    int number_of_team=min(a,count3);
    if(number_of_team==0) cout<<0<<endl;
    else{
        cout<<number_of_team<<endl;
        flag=true;
    }
    if(flag==true){
        for(int i=0; i<v.size(); i++){
            if(v[i]==1){
                cout<<i+1;
                for(int j=0;j<v.size(); j++){
                    if(v[j]==2){
                        cout<<j+1;
                        for(int k=0 ; k<v.size(); k++){
                            if(v[k]==3){
                                cout<<k+1;
                                cout<<endl;
                                break;
                            }
                        }
                        
                    }
                }
                
            }
        }
    }
}
    
