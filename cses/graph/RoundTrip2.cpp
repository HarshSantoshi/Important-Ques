#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>parent;
int cycleNode = -1;
bool cycle(int node , vector<int>&vis , vector<int>&pathvis){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : adj[node]){
        if(pathvis[it]){
            cycleNode = it;
            parent[it] = node;
            return true;
        }
        if(!vis[it]){
            parent[it] = node;
            if(cycle(it , vis , pathvis)){
                return true;
            }
        }
        
    }
    pathvis[node] = 0 ;
    return false;
}
int main(){
    int n , m ;
    cin>>n>>m;
    adj.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<m;i++){
        int src , dest;
        cin>>src>>dest;
        adj[src].push_back(dest);
    }
    vector<int>vis(n+1 , 0);
    vector<int>pathvis(n+1,0);
    bool isCycle = false;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            if(cycle(i , vis , pathvis)){
                isCycle = true;
                break;
            }
        }
    }
  
    
    if(!isCycle){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
     
        // cout<<cycleNode<<" ";
        int curr = cycleNode;
        vector<int>arr;
        while(parent[curr]!=cycleNode){
            // cout<<parent[curr]<<" ";
            arr.push_back(parent[curr]);
            curr = parent[curr];
        }
        reverse(arr.begin() , arr.end());
        cout<<arr.size() + 2<<endl;
        cout<<cycleNode<<" ";
        for(auto it : arr){
            cout<<it<<" ";
        }
        cout<<cycleNode<<" ";

        cout<<endl;
    }

}