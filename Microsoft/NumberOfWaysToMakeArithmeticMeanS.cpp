#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

int solve(vector<int> &nums,int s){
    unordered_map<int,int> mp;
    int sum = 0,res = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum += (nums[i]-s);
        if(sum == 0){
            res++;
        }
        if(mp.find(sum) != mp.end()){
            res += mp[sum];
        }
        mp[sum]++;
    }
    return res;
}

int main() {
    int n,s;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>s;
    cout<<solve(nums,s)<<endl;
    return 0;
}