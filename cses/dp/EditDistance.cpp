// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<vector<ll>>dp;
long long solve(int i , int j , string &s , string & t , int n , int m){
    if(i == n && j == m)
    {
        return 0;
    }
    if(i >= n){
        return m- j;
    }
    if(j >= m)return n- i;
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1 = INT_MAX , op2 = INT_MAX;
    ll op3 = INT_MAX ;
    if(s[i] == t[j]){
        return dp[i][j] = solve(i+1 , j+1 , s , t , n , m);
    }
    else{
        op1 = solve(i , j+1 , s , t , n , m);
        op2 = solve(i+1 , j , s , t , n , m);
        op3 = solve(i+1 , j+1 , s , t , n, m);
    }
    return dp[i][j] = min({op1 +1, op2+1 , op3+1});
}
int main() {
    string s ,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    dp.resize(n , vector<ll>(m,-1));
    int ans = solve(0 , 0 , s , t, n , m);
    cout<<ans<<endl;
    return 0;
}