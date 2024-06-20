#include "bits/stdc++.h"
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
int remove(int target , vector<vector<int>>&matrix,int n , int m){

}
void solve()
{
    int n,m ;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int k;
    cin>>k;
    int steps = 0 ;
    for(int i=1;i<=k;i++){
        steps+=remove(i , matrix,n,m);
    }
    cout<<steps<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    // #endif

    solve();

    return 0;
}
