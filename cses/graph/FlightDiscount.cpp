#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        ll src, dest, cost;
        cin >> src >> dest >> cost;
        adj[src].push_back({dest, cost});
    }
    
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vector<ll>> distance(n + 1, vector<ll>(2, LLONG_MAX));
    distance[1][1] = 0;
    pq.push({0, 1, 1});
    
    while (!pq.empty()) {
        auto [cost, node, coupon] = pq.top();
        pq.pop();
        
        if (cost > distance[node][coupon]) {
            continue;
        }
        
        if (node == n) {
            cout << cost << endl;
            return 0;
        }
        
        for (auto [neigh, toReachCost] : adj[node]) {
            if (distance[neigh][coupon] > cost + toReachCost) {
                distance[neigh][coupon] = cost + toReachCost;
                pq.push({distance[neigh][coupon], neigh, coupon});
            }
            if (coupon && distance[neigh][coupon - 1] > cost + toReachCost / 2) {
                distance[neigh][coupon - 1] = cost + toReachCost / 2;
                pq.push({distance[neigh][coupon - 1], neigh, coupon - 1});
            }
        }
    }
    
    cout << "-1" << endl;
    return 0;
}
