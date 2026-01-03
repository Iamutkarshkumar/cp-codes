#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[4];
    int sum=0;
    string str;
    for(int i=0;i<4;i++){
       cin>>arr[i];
    }
    cin>>str;

    int a=0;
    int b=0;
    int c=0;
    int d=0;  
    for(int i=0;i<str.size();i++){
        if(str[i]=='1') a++;
        if(str[i]=='2') b++;
        if(str[i]=='3') c++;
        if(str[i]=='4') d++;
    }  
    cout<<(arr[0]*a)+(arr[1]*b)+(arr[2]*c)+(arr[3]*d); 
}
