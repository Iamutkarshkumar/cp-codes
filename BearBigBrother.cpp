#include<iostream>
using namespace std;
int main(){
    int l,b;
    cin>>l>>b;
    for(int i=1 ; ; i++){
        l*=3;
        b*=2;
        if(l>b){
            cout<<i;
            break;
        }
    }

}