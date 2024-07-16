#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<int>primes;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)return false;
    }
    return true;
}
void precompute(){
    for(int i=2;i<=100;i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
}
const int MOD = 1e9 + 7;
vector<vector<int>>adj;
vector<vector<int>>dp;
void dfs(int node , int par){
    for(auto neigh : adj[node]){
        if(neigh == par){
            continue;
        }
        dfs(neigh , node);
        for(int i=0;i<primes.size();i++){
            ll cnt = 0;
            for(int j=0;j<primes.size();j++){
                if(isPrime(primes[i]+primes[j])){
                    continue;
                }
                cnt += dp[neigh][j];
                cnt = cnt%MOD;
            }
            dp[node][i] *= cnt;
            dp[node][i] %= MOD;
        }
    }

}
void solve()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    dp.resize(n+1 , vector<int>(25,1));
    for(int i=0;i<n-1;i++){
        int x , y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1 ,-1 );
    ll ans = 0 ;
    for(int i=0;i<25;i++){
        ans = (ans +  dp[0][i])%MOD;
    }
    cout<<ans<<endl;

}

int main()
{
    int t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }
}