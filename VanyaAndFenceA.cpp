#include<iostream>
using namespace std;
int main(){
    int n,h,x,count;
    cout<<"enter no. of person and height of fence";
    cin>>n>>h;
    for(int i=1 ; i<n+1 ; i++){
        cout<<"enter height of persons";
        cin>>x;
        if(x>h) count =count +2;
        else count = count+1;
    }
    cout<<count;
}