#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);

    //METHOD 1

    // set <char> set;
    // for(int i=0;i<str.size();i++){
    //     set.insert(str[i]);
    // }
    // if(set.size()%2==0) cout<<"CHAT WITH HER!";
    // else cout<<"IGNORE HIM!"; 

    

    //METHOD 2
   
    int a[26] = {0};
    for(int i=0;i<str.length();i++){
        a[str[i]-'a']++;
    }
    int count = 0;
    for(int i = 0;i<26;i++){
        if(a[i] > 0){
            count++;
        }
    }
    if(count%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";

}