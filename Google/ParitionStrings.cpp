#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int helper(int idx ,vector<int>&nums , int n , int m  , int k ,vector<vector<int>>&dp){
  
    if(idx == n){
        return 0;
    }
    if(k == 1){
        if(nums[idx]%2== 0 && nums[n-1]%2 == 1){
            return 1;
        }
        else return 0;
    }
    if(nums[idx]%2){
        return 0;
    }
    if(dp[idx][k] != -1){
        return dp[idx][k];
    }
    int ans = 0;
    for(int i=idx+m - 1;i<n;i++){
        if(nums[i]%2){
            ans = (ans + helper(i + 1 , nums , n , m , k-1,dp))%mod;
        }
    }
    return dp[idx][k] = ans%mod;
}


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        nums[i] = s[i] - '0';
    }
    if(nums[0]%2){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>>dp(n+1 , vector<int>(k+1,-1));
    int ans = helper(0,nums, n, m, k , dp);
    cout<<ans%mod<<endl;
    return 0;
}