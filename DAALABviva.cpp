#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& a,vector<int>& b, vector<int>& res){
    int i=0,j=0,k=0;
    while(i<a.size() and j<b.size()){
        if(a[i]<=b[j]){
            res[k++]=a[i++];
        }
        else{
            res[k++]=b[j++];
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            res[k++]=b[j++];
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            res[k++]=a[i++];
        }
    }
}
void MergeSort(vector<int>& v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0; i<n1; i++){
        a[i]=v[i];
    }
    for(int i=0; i<n2; i++){
        b[i]=v[i+n1];
    }
    MergeSort(a);
    MergeSort(b);
    merge(a,b,v);

}

pair<int, int> help(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }

    return {-1, -1};
}
int main(){
    int n;
    cout<<"enter size of array :";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    MergeSort(v);

    int target;
    cout<<" enter target : ";
    cin>>target;


    auto ans= help(v,target);
    if(ans.first!=-1) cout<<ans.first<<" "<<ans.second<<endl;


}
