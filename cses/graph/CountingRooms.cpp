// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

vector<vector<ll>> dp;
vector<int>dir = {1,0,-1,0,1};
void dfs(int x , int y , vector<vector<char>>&graph  , vector<vector<int>>&vis){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int newx = x + dir[i];
        int newy = y + dir[i+1];
        if(newx >=0 && newy >=0 && newx <graph.size() && newy<graph[0].size() && graph[newx][newy] == '.' && vis[newx][newy] == 0){
            dfs(newx,newy,graph,vis);
        }
    }
}
int main()
{
    int n , m;
    cin>>n>>m;
    int ans = 0 ;
    vector<vector<int>>vis(n , vector<int>(m,0));
    vector<vector<char>>graph(n , vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == '.' && vis[i][j] == 0){
                ans ++ ;
                dfs(i , j , graph , vis);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

