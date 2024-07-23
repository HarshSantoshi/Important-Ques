#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int src, dest;
        cin >> src >> dest ;
        adj[src].push_back(dest);
    }
    vector<int>indegree(n+1 , 0);
    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(auto it : adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    queue<int>q;
    vector<int>dp(n+1 , 0);
    for(int i=2;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(q.size()){
        int curr = q.front();
        q.pop();
        for(auto dest : adj[curr]){
            if(--indegree[dest] == 0 && dest!=1){
                q.push(dest);
            }
        }
    }
    q.push(1);
    dp[1] = 1;
    int mod = 1e9 + 7;
   
    
    while(q.size()){
        int curr = q.front();
        q.pop();
        // cout<<curr<<": ";

        for(auto it : adj[curr]){
            if(--indegree[it] == 0)
                q.push(it);
            dp[it] = (dp[it] + dp[curr]) % mod;
            // cout<<it<<"="<<dp[it]<<" ";
            
        }
        // cout<<endl;
    }
   
    
    cout<<dp[n]<<endl;
    
    return 0;
}
