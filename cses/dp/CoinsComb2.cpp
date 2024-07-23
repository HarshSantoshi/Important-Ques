
#include <bits/stdc++.h>
using namespace std;
int mod =1e9+ 7;
vector<vector<long long>>dp;
// int countWays(int idx , vector<int>&coins, long long target ){
//     if(target == 0){
//         return 1;
//     }
//     if(idx >= coins.size()){
//         return 0;
//     }
//     if(dp[idx][target]!=-1)return dp[idx][target];
//     int take = 0 , nottake =0 ;
//     if(target - coins[idx] >=0 ){
//         take =  countWays(idx  ,coins , target - coins[idx]);
//     }
//     nottake = countWays(idx + 1 ,  coins , target);
//     return dp[idx][target] = (take + nottake)%mod;
// }
int main() {
    long long n , target;
    cin>>n>>target;
    vector<int>coins(n,0);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    // dp.resize(n +1, vector<long long>(target + 1, 0));
    // for(int i=0;i<n;i++){
    //     dp[i][0] = 1;
    // }
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    prev[0] =1 ;
    curr[0] = 1;
    for(int i=n-1;i>=0;i--){
        for(int sum = 1 ; sum <= target;sum++){
            int nottake = prev[sum];
            int take = 0 ;
            if(sum - coins[i] >=0){
                take = curr[sum - coins[i]];
            }
            curr[sum] = (take + nottake)%mod;
        }
        prev = curr;
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=target;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<prev[target]<<endl;
    
    // int ans = countWays(0 , coins , target);
    
    // cout<<ans%mod << endl;
}