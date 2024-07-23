#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , m ;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int src,dest;
        cin>>src>>dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    vector<int>distance(n+1 , INT_MAX);
    vector<int>parent(n+1, 0);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

    pq.push({0,1});
    distance[1] = 0 ;
    parent[1] = 1;
    while(pq.size()){
        int dist = pq.top().first;
        int node = pq.top().second;
        if(node == n){
            break;
        }
        pq.pop();
        for(auto neigh : adj[node]){
            if(dist + 1 < distance[neigh]){
                distance[neigh] = dist + 1;
                parent[neigh] = node;
                pq.push({distance[neigh] , neigh});
            }
        }
    }

    if(distance[n] == INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<distance[n]+1<<endl;
        int curr = n;
        vector<int>path;
        while(parent[curr]!= curr ){
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin() , path.end());
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}