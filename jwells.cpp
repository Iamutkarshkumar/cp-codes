#include <bits/stdc++.h>
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
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, maxJewels=INT_MIN;
vector<vector<int>> grid, bestPath;
vector<vector<int>> visited;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y,int jewels,vector<vector<int>> &path){
    if(x==n-1 && y==n-1){ 
        if(jewels>maxJewels){
            maxJewels=jewels;
            bestPath=path;
        }
        return;
    }
    for(int k=0;k<4;k++){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny] && grid[nx][ny]!=1){
            visited[nx][ny]=1;
            path[nx][ny]=1;
            dfs(nx,ny,jewels+(grid[nx][ny]==2),path);
            path[nx][ny]=0;
            visited[nx][ny]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    grid.assign(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>grid[i][j];

    visited.assign(n,vector<int>(n,0));
    vector<vector<int>> path(n,vector<int>(n,0));

    if(grid[0][0]==1 || grid[n-1][n-1]==1){
        cout<<"No path\n";
        return 0;
    }

    visited[0][0]=1;
    path[0][0]=1;
    dfs(0,0,(grid[0][0]==2),path);

    if(maxJewels==INT_MIN){
        cout<<"No path\n";
        return 0;
    }

    // mark best path with 3
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bestPath[i][j]) grid[i][j]=3;
        }
    }

    cout<<"Max Jewels: "<<maxJewels<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}