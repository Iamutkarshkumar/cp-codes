#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<string> v;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(abs(a-b)%2==0){
            v.push_back("Bob");
        }
        else{
            v.push_back("Alice");
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}
