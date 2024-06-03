#include <bits/stdc++.h>
using namespace std;

vector<int>solve(vector<string>&commands , int N){
    unordered_map<string ,int>mp;
    string temp = "";
    for(auto i : commands[0]){
        temp+=i;
        mp[temp] = 0;
    }
    vector<int>ans;
    ans.push_back(0);
    
    for(int i=1;i<N;i++){
        string temp ="";
        int possible = i-1;
        for(auto it : commands[i]){
            temp+= it;
            if(mp.find(temp) != mp.end()){
                possible = mp[temp];
            }
            mp[temp] = i;
        }
        ans.push_back(possible+1);
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;

    vector<string>commands;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        commands.push_back(s);
    }
    vector<int>ans = solve(commands , N);
    for(auto it  : ans){
        cout<<it<<" ";
    }

    return 0;
}
