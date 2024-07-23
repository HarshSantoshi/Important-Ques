#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int src, dest;
        cin >> src >> dest ;
        adj[src].push_back({dest,1});
    }
    
    // priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>q;
    set<pair<int,int>>q;
    q.insert({0,1});
    vector<int>parent(n+1,-1);
    vector<int>dist(n+1,INT_MIN);
    dist[1] = 0;
   
    while(q.size()){
        auto top = *q.begin();
        int node = top.second;

        q.erase(top);
        
        for(auto it:adj[node]){
            int neigh = it.first;
            int cost = it.second;
            if(dist[neigh] < dist[node] + cost){
                parent[neigh] = node;
                q.erase({dist[neigh] , neigh});
                dist[neigh] = dist[node] + cost;
                q.insert({dist[neigh] , neigh});
            }
            
        }
    }
    int curr = n;
    vector<int>ans;
    while(parent[curr]!=-1){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);
    if(ans.size() == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    reverse(ans.begin() , ans.end());
    
    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    
    
    return 0;
}
