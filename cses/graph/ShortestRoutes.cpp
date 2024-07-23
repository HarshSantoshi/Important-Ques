#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        ll a , b , c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1] = 0 ;
    priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll, ll>>>pq;
    pq.push({0 , 1});
    while(pq.size()){
        ll currCity = pq.top().second;
        ll currDist = pq.top().first;
        pq.pop();
        if (currDist > dist[currCity]) continue;
        for(auto it : adj[currCity]){
            ll nextCity = it.first;
            ll nextDist = it.second;
            if(dist[nextCity] > currDist + nextDist){
                dist[nextCity] = currDist + nextDist;
                pq.push({dist[nextCity] , nextCity});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;


    
}
