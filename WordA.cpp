#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int upper=0;
    int lower=0;
    getline(cin,str);
    for(int i=0;i<str.size();i++){
        if(str[i] >= 65 && str[i] <=90) upper++;
        else if(str[i] >= 97 && str[i] <=122) lower++;
    }
    for(int i=0;i<str.size();i++){
    if(upper<=lower) {
            str[i]=tolower(str[i]);
            cout<<str[i];    
        } 
        if(upper>lower) {
            str[i]=toupper(str[i]);
            cout<<str[i];    
        }
    }   

    

    
}    


       

        
        

    
    
    
    
