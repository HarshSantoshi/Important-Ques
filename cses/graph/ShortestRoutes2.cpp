#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m,q;
    cin >> n >> m>>q;

    // vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<ll>>ans(n +1, vector<ll>(n+1,LLONG_MAX));
    for(int i=0;i<m;i++){
        ll a , b , c;
        cin>>a>>b>>c;
        ans[a][b] = min(ans[a][b] , c);
        ans[b][a] = min(ans[b][a] , c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                ans[i][i] = 0 ;
            }
        }
    }
    vector<vector<ll>>queries;
    for(int i=0;i<q;i++){
        ll src , dest;
        cin>>src>>dest;
        queries.push_back({src , dest});
    }
    
    for(int k = 1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][k] == LLONG_MAX || ans[k][j] == LLONG_MAX){
                    continue;
                }
                ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
            }
        }
    }

    for(auto it : queries){
        if(ans[it[0]][it[1]] == LLONG_MAX){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans[it[0]][it[1]]<<endl;
    }
    

    
}
