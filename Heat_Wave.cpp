#include <bits/stdc++.h>
using namespace std;
int maximumLength(vector<int>& nums) {
       int count=0;
       for(int i=1;i<nums.size();i++){
        if((nums[i-1]+nums[i])%2!=(nums[i]+nums[i+1])%2){
            i++;
        }
        else count ++;
       } 
       return count*2;
    }

int main() {
	vector<int> arr={1, 2, 3, 4};
 	cout << maximumLength(arr);

}
