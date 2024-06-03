#include <bits/stdc++.h>
using namespace std;
int solve(int n , vector<int>&g_from , vector<int>&g_to){
    //First do dfs from 0 and find the farthest node
    //Then do second dfs from this farthest node
}
int main()
{
    int N;
    cin>>N;
    vector<int>g_from(N-1 , 0);
    vector<int>g_to(N-1 , 0);
    for(int i=0;i<N-1;i++){
        cin>>g_from[i];
    }
    for(int i=0;i<N-1;i++){
        cin>>g_to[i];
    }
    int maxTime = solve(N , g_from , g_to);
    cout<<maxTime;

    return 0;
}
