
#include <bits/stdc++.h>
using namespace std;
const int mod =1e9+ 7;
#define ll long long 
vector<vector<ll>>dp;
ll solve(ll idx , vector<ll>&arr , ll prev,ll m){
    
    if(arr[idx] && abs(prev - arr[idx])>1)return 0;
    if((prev <=0 || prev >m))return 0;
    if(idx == arr.size() - 1){
        if(arr[idx]){
            return 1;
        }
        else{
            ll res = 0;
            if(prev-1 >=1){
                res ++ ;
            }
            if(prev + 1<=m){
                res ++ ;
            }
            if(prev >=1 && prev<=m){
                res ++ ;
            }
            // cout<<prev << " "<<res<<endl;
            return res;
        }
    }
    if(arr[idx]){
        return solve(idx+1 , arr , arr[idx],m);
    }
    if(dp[idx][prev]!=-1){
        return dp[idx][prev];
    }
    ll op1 = 0 , op2 = 0 , op3= 0 ;
    op1 = solve(idx + 1 , arr , prev - 1 , m);
    op2 = solve(idx + 1 , arr , prev + 1 ,m);
    op3 =  solve(idx + 1 , arr , prev ,m);
    return dp[idx][prev] =( op1 + op2 + op3)%mod;

}
int main() {
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    vector<ll>arr(n, 0);
    int zero =0 ;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    if(n == 1){
        if(arr[0] == 0){
            cout<<m<<endl;
        }
        else cout<<1<<endl;
        return 0 ;
    }
    dp.resize(n+1 , vector<ll>(m+1,-1));
    ll ans = 0;
    if(arr[0] == 0){
        for(ll i=1;i<=m;i++){
            ans = (ans + solve(1 , arr , i,m))%mod;
        }
    }
    else{
        ans = solve(1 , arr , arr[0] , m);
    }
    cout<<ans<<endl;
    
}