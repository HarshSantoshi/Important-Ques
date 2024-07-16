// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&mat , int n){
    int total = pow(2,n) - 1;
    int ans = 0;
    for(int comb=0;comb<=total;comb++){
        int sum = 0 ;
        for(int i=0;i<n;i++){
            if(comb& (1<<i)){
                for(int j=i+1;j<n;j++){
                    if(comb &(1<<j)){
                        sum += mat[i][j];
                    }
                }
            }
        }
        ans = max(ans , sum);
    }
    return ans;
}
int main() {
    vector<vector<int>>mat = {{0 , 10 , 10 , 10},{10,0,10,10} , {10 , 10 , 0 , -1}, {10 , 10 , -1 , 0}};
    int n = mat.size();
    int ans = solve(mat , n);
    cout<<ans<<endl;
    

    return 0;
}