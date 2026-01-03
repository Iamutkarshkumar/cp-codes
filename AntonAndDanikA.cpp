//PYTHON CODE
// n=int(input())
// a=input()
// A=0
// D=0
// for i in a:
//     if i=="A":
//         A+=1
//     else:
//         D+=1
// if A>D:
//     print("Anton")
// elif D>A:
//     print("Danik")
// else:
//     print("Friendship")
#include<iostream>
using namespace std;
int main(){
    string n;
    cin>>n;
    int A,D;
    A=0;
    D=0;
    for(int i=0 ; ; i++){
        if(i=="A") A+=1;
        else D+=1;
    }
    if (A>D) cout<<"Anton";
    if(D>A) cout<<" Danik";
    if(D==A)cout<<"Friendship";
}
    