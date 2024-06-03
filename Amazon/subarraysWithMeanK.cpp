#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int f(vector<int> &rank,int k){
    int n = rank.size();
    unordered_map<int,int> mp;
    int res = 0,sum = 0;
    for(int i=0;i<n;i++){
        sum += (rank[i]-k);
        if(sum == 0){
            res++;
        }
        if(mp.find(sum)!=mp.end()){
            res += mp[sum];
        }
        mp[sum]++;
    }
    return res;
}
vector<int> solve(vector<int> &rank){
    int n = rank.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i] = f(rank,rank[i]);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector<int> rank(n);
    for(int i=0;i<n;i++){
        cin>>rank[i];
    }
    vector<int> ans = solve(rank);
    for(auto c:ans){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}