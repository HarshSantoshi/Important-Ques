// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&trips , int n , int x){

    priority_queue<int>maxHeap;
    for(auto it : trips){
        maxHeap.push(it);
    }
    while(x){
        int highestTrip = maxHeap.top();
        maxHeap.pop();
        //using coupon
        x--;
        highestTrip = highestTrip/2;
        maxHeap.push(highestTrip);
    }
    int ans = 0;
    while(maxHeap.size()){
        ans += maxHeap.top();
        maxHeap.pop();
    }
    return ans;
}
int main() {
    int N , X;
    cin>>N>>X;
    vector<int>trips(N,0);
    for(int i=0;i<N;i++){
        cin>>trips[i];
    }
    int res = solve(trips , N, X);
    cout<<res<<endl;

    return 0;
}