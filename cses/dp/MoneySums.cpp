// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<vector<int>>dp;
vector<int>ans;
void solve(vector<int>&coins , int n){
    ll sum = 0 ;
    for(int i : coins){
        sum += i;
    }
    vector<int>vis(sum + 1 , 0);
    vis[0] = 1;
    for(int i=0;i<n;i++){
        for(int v = sum ; v >= coins[i];v--){
            vis[v] |= vis[v - coins[i]];
        }
    }
    int size = 0 ;
    for(int i=1;i<=sum;i++){
        size += vis[i];
    }
    cout<<size<<endl;
    for(int i=1;i<=sum;i++){
        if(vis[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}
int main() {
    int n ;
    cin>>n;
    vector<int>coins(n,0);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin() , coins.end());
    solve(coins , n);
    return 0;
}