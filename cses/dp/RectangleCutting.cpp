// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<vector<int>>dp;
ll solve(int a , int b){
    if(a<b)return solve(b,a);
    if(a == b)return 0;
    if(a == 1){
        return b-1;
    }
    if(b == 1)return a-1;
    if(dp[a][b] !=-1) return dp[a][b];
    int len = a; //2
    int breadth = b; // 8
    ll ans = INT_MAX;
    for(int cut = 1 ; cut < breadth ; cut++){
        ans = min(ans ,1 + solve(len , cut) + solve(len ,breadth-cut));
    }
    for(int cut = 1 ; cut < len ; cut++){
        ans = min(ans ,1 + solve(cut , breadth) + solve(len-cut ,breadth));
    }
    
    return dp[a][b] = ans;
}

int main() {
    int a , b;
    cin>>a>>b;
    dp.resize(502 , vector<int>(502 , -1));
    ll ans = solve(a,b);
    cout<<ans<<endl;
    
    return 0;
}