#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>>edges;
    for(int i=0;i<m;i++){
        ll a , b , c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<ll> dist(n+1,LLONG_MIN);
    dist[1] = 0 ;
    for(int i=1;i<=n;i++){
        for(auto it : edges){
            int src = it[0];
            int dest = it[1];
            int cost = it[2];
            if(dist[src] != LLONG_MIN ){
                dist[dest] = min(dist[dest] , dist[src] + cost);
                dist[dest] = max(dist[dest] , LLONG_MIN);
            }
        }
    }
    bool hascycle = false;
    for (auto it : edges) {
        int src = it[0];
        int dest = it[1];
        int cost = it[2];
        dist[dest] = max(dist[dest] , LLONG_MIN);
        if (dist[src]!=LLONG_MIN && dist[src] + cost < dist[dest]) {
            hascycle = true;
            break;
        }
    }

    if (dist[n] == LLONG_MIN || hascycle) {
        cout << "-1" << endl;
    } else {
        cout << -1*dist[n] << endl;
    }
    
}
