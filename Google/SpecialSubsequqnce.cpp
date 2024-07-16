// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;
int helper(int idx , string&s , int k , int n , string out){
    if(idx == n){
        if(out.length() == k)return 1;
        return 0;
    }
    int take = 0 , nottake = 0 ;
    if(mp[s[idx]] == 0){
        mp[s[idx]]++;
        out+=(s[idx]);
        take = helper(idx + 1 , s , k , n ,out);
        mp[s[idx]]--;
        out.pop_back();
    }
    nottake = helper(idx , s , k , n , out);
    return take + nottake;
}
int solve(string s , int k , int n){
    
    return helper(0 , s , k , n , "");
}
int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n = s.length();
    int ans = solve(s , k , n);
    cout<<ans<<endl;
    return 0;
}