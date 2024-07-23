#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m,k;
    cin >> n >> m>>k;
    
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        ll src, dest, cost;
        cin >> src >> dest >> cost;
        adj[src].push_back({dest, cost});
    }
    vector<ll>ans;
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<vector<ll>>distance(n+1 , vector<ll>(k,LLONG_MAX));
  
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll dist = top.first, node = top.second;
        
        if(distance[node][k-1] < dist)continue;
        
        for(auto neigh : adj[node]){
            ll dest = neigh.first;
            ll cost = neigh.second;
            if(distance[dest][k-1] > cost + dist){
                distance[dest][k-1] = cost + dist;
                sort(distance[dest].begin() , distance[dest].end());
                pq.push({cost + dist, dest});
            }
            
        }
    }
  
    for(int j=0;j<k;j++){
        cout<<distance[n][j]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
