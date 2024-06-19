#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

vector<long long> solve(int n , int k)
{
    vector<string>allStrings;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        allStrings.push_back(s);
    }
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        string temp ="";
        for(int j=0;j<k;j++){
            temp+=(allStrings[i][j]);
          
            mp[temp]++;
        }
    }
    // for(auto it : mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    vector<long long>res;
    for(int i=0;i<n;i++){
        string temp ="";
        long long ans = 0;
        for(int j=0;j<k;j++){
            temp+=allStrings[i][j];
            ans += mp[temp];
        }
        res.push_back(ans);
    }
    return res;

}

    int main()
    {
        int n,k;
        cin >> n>>k;

        vector<long long>ans =  solve(n,k);
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }