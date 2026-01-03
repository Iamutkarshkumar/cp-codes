// #include <bits/stdc++.h>
// #include<string>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         string s;
//         cin>>s;
//         int ans1=s[0]-'0';
//         int ans2=s[1]-'0';
//         int ans=(ans1*10)+ans2;

//         if(ans>=13){
//             cout<<"0"<<ans-12;
//             for(int i=2;i<6;i++){
//                 cout<<s[i];
//             }
//             cout<<"PM"<<endl;
//         }
//         else if(ans==12){
//             cout<<"12";
//             for(int i=2;i<6;i++){
//                 cout<<s[i];
//             }
//             cout<<"PM"<<endl;
//         }
//         else if(ans==0){
//             cout<<"12";
//             for(int i=2;i<6;i++){
//                 cout<<s[i];
//             }
//             cout<<"AM"<<endl;

//         }
//         else cout<<s<<" "<<"AM"<<endl;
//     }
    
// }


#include <bits/stdc++.h>
#include<string>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int ans1=s[0]-'0';
        int ans2=s[1]-'0';
        int ans=(ans1*10)+ans2;
        
        if(ans>=13){
            if(ans-12<10) cout<<"0";
            cout<<ans-12;
            for(int i=2;i<5;i++){
                cout<<s[i];
            }
            cout<<" PM"<<endl;
        }
        else if(ans==12){
            cout<<"12";
            for(int i=2;i<5;i++){
                cout<<s[i];
            }
            cout<<" PM"<<endl;
        }
        else if(ans==0){
            cout<<"12";
            for(int i=2;i<5;i++){
                cout<<s[i];
            }
            cout<<" AM"<<endl;

        }
        else {
            if(ans<10) cout<<"0";
            cout<<ans;
            for(int i=2;i<5;i++){
                cout<<s[i];
            }
            cout<<" AM"<<endl;
        }
    }
    
}

