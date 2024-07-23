#include <bits/stdc++.h>
using namespace std;

bool dfs(int node , vector<vector<int>>&adj , int par , vector<int>&vis , vector<int>&parent , int& start , int &end){
    vis[node] = 1;
    parent[node] = par;
    for(auto it : adj[node]){
        if(it == par){
            continue;
        }
        if(vis[it] == 0){
            if(dfs(it , adj , node , vis ,parent , start , end))return true;
        }
        else{
            start = it;
            end = node;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    vector<int>vis(n+1,0);
    vector<int>path;
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        int start = 0 , end = 0;
        if(vis[i] == 0){
            if(dfs(i , adj , -1 , vis , parent , start , end)){
                int curr = end;
                path.push_back(end);
                while(end!= start){
                    path.push_back(parent[end]);
                    end = parent[end];
                }
                path.push_back(curr);
                cout<<path.size()<<endl;
                for(auto it : path){
                    cout<<it<<" ";
                }
                cout<<endl;
                return 0;
            }
            
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;

}