#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class DSU{
    public :
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void merge(int x, int y){
        x = findParent(x);
        y = findParent(y);
        if(x == y){
            return ;
        }
        if(size[x] < size[y]){
            parent[x] = y;
            size[y] += size[x];
        }
        else{
            parent[y] = x;
            size[x] += size[y];
        }
    }
};
string bfs(int startX, int startY, vector<vector<char>>& graph, vector<vector<int>>& vis, int destX, int destY) {
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int src , dest;
        cin>>src>>dest;
        adj[src].push_back(dest);
    }
    vector<int>vis(n+1 , 0);
    int ans = 0 ;
    DSU dsu(n);
    vector<vector<int>>edges;
    for(int i=1;i<adj.size();i++){
        int node1 = i;
        for(auto neigh : adj[i]){
            int node2 = neigh;
            dsu.merge(node1 ,node2);
        }
    }

    for(int i=2;i<=n;i++){
        dsu.parent[i] = dsu.findParent(dsu.parent[i]);
        dsu.parent[i-1] = dsu.findParent(dsu.parent[i-1]);
        if(dsu.parent[i] != dsu.parent[i-1]){
            ans ++ ;
            edges.push_back({dsu.parent[i-1] , dsu.parent[i]});
            dsu.merge(dsu.parent[i-1] , dsu.parent[i]);
        }
    }
    cout<<ans<<endl;
    for(auto it : edges){
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    return 0;
}
