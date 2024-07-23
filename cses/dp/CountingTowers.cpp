// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<vector<int>>dp;
void solvebefore(){
    int n = 1e6;
     //0 not linked tiles
    //1 linked tiles
    // dp[i][0] = dp[i+1][1] + dp[i+1][0] //used 2 width or 1width 2tiles
    //            dp[i+1][0]  // extended both
    //            dp[i+1][0]*2 // extend just one
    
    // dp[i][1] = dp[i+1][1] + dp[i+1][0];
    //            dp[i+1][0]
    // if(n == 1){
    //     cout<<2<<endl;
    // }
    dp.resize(n+2 , vector<int>(2,0));
    dp[1][0] = dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        ll op1 = (dp[i-1][1] + dp[i-1][0])%mod;
        ll op2 = dp[i-1][0]%mod;
        ll op3 = (2*dp[i-1][0])%mod;
        ll op4 = dp[i-1][1]%mod;
        dp[i][0] = (op1+ //used 2 width or 1width 2tiles
                    op2+ // extended both
                    op3)%mod;
        dp[i][1] = (op1+ //used 2 width or 1width 2tiles
               op4)%mod ;
    }
}
int main() {
    int t;
    cin>>t;
    solvebefore();
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0] + dp[n][1])%mod<<endl;
        
    }
    return 0;
}