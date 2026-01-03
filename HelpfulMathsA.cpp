#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<char> arr;
    for(int i=0; i<s.size(); i+=2){
        arr.push_back(s[i]);
    }
    sort(arr.begin(), arr.end());
    if(arr.size()==1) cout<<arr[0];
    else{
        cout<<arr[0]<<"+";
        for(int i=1;i<s.length()/2;i++){
        cout<<arr[i]<<"+";
        }
        cout<<arr[s.length()/2];
    }
}
    
