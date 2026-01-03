#include<bits/stdc++.h>
using namespace std;
static const int mod=1000000007;
int solve (int n, vector<int> a) {
   static int dp[2][3][3];
   memset(dp,0,sizeof(dp));
   dp[0][0][0]=1;
   int cur=0,nxt=1;
   for(int i=0;i<n;i++){
    memset(dp[nxt],0,sizeof(dp[nxt]));
    int p=a[i] & 1;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            int v=dp[cur][j][k];
            if(!v) continue;
            dp[nxt][j][k]=(dp[nxt][j][k]+v)%mod;
            if(p==0){
                if(j<2) dp[nxt][j+1][0]=(dp[nxt][j+1][0]+v)%mod;
            }
            else if(k<2) dp[nxt][0][k+1]=(dp[nxt][0][k+1]+v)%mod;
        }
    }
    cur^=1;nxt^=1;

   }
   int ans=0;
   for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
        if(j | k) ans=(ans+dp[cur][j][k])%mod;
    }
   }
   return ans;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        int out_;
        out_ = solve(N, A);
        cout << out_;
        cout << "\n";
    }
}
















// #include<bits/stdc++.h>
// using namespace std;

// long long solve (int n, vector<int> a, int m, vector<vector<int> > b) {
//    vector<int> p(n);
//    iota(p.begin(),p.end(),0);
//    function<int(int)> f=[&](int x){
//     return p[x]==x ? x : p[x] = f(p[x]); 
//    };
//    for(auto e :b){
//     int u=f(e[0]-1),v=f(e[1]-1);
//     if(u!=v) p[v]=u;
//     }
//     unordered_map<int,vector<int>> mp;
//     for(int i=0;i<n;i++) mp[f(i)].push_back(i);

//     long long ans=0;
//     for(auto &kv: mp){
//         auto &idx =kv.second;
//         vector<int> v;
//         v.reserve(idx.size());
//         int cnt_neg=0;
//         for(int i: idx){
//             v.push_back(a[i]);
//             if((i+1)%2 ==0 ) cnt_neg++;
//         }
//         sort(begin(v),end(v));
//         long long sum=0;
//         for(int i=0;i<cnt_neg;i++) sum-=v[i];
//         for(int i=cnt_neg;i<v.size();i++) sum+=v[i];
//         ans+=sum;
//     }
//     return ans;
// }

   


// int main() {

//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int T;
//     cin >> T;
//     for(int t_i = 0; t_i < T; t_i++)
//     {
//         int N;
//         cin >> N;
//         vector<int> A(N);
//         for(int i_A = 0; i_A < N; i_A++)
//         {
//         	cin >> A[i_A];
//         }
//         int M;
//         cin >> M;
//         vector<vector<int> > B(M, vector<int>(2));
//         for (int i_B = 0; i_B < M; i_B++)
//         {
//         	for(int j_B = 0; j_B < 2; j_B++)
//         	{
//         		cin >> B[i_B][j_B];
//         	}
//         }

//         long long out_;
//         out_ = solve(N, A, M, B);
//         cout << out_;
//         cout << "\n";
//     }
// }