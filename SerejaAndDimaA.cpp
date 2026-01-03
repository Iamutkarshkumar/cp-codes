#include <bits/stdc++.h>
using namespace std;
int main(){
  int sereja=0;
  int dima=0;
  int chance=0;
  int max=0;
  int n;
  cin>>n;
  int v[n];
  int start=0;
  int end=n-1;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
   
  for(int i=0;i<n;i++){
    if(v[start]>=v[end]){
      max=v[start];
      start++;
    }
    else{
      max=v[end];
      end--;
    }
    
    if(chance%2==0){
      sereja+=max;
      chance++;
    }
    else{
      dima+=max;
      chance++;
    }
  }
  cout<<sereja<<" "<<dima;
}

