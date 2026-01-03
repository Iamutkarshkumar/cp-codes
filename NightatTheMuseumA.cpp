#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int count=0;
    char j='a';
    for(int i=0;i<str.size();i++){
        if(abs(j-str[i])<=13) count+=abs(j-str[i]);
        else count+=(26-abs(j-str[i]));
        j=str[i];
    }
    cout<<count;
}