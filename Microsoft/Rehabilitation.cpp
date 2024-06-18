#include<bits/stdc++.h>
using namespace std;
long long solution(vector<int>&A , int x, int y){
    
    int n = A.size();
    vector<long long>prefix(n+1 , 0);
    for(int i=0;i<y;i++){
        prefix[i] = A[i];
    }
    for(int i=y;i<n;i++){
       prefix[i] = A[i] + prefix[i-y];
    }
    long long ans = 1e16;
    for(int i=n-1;i>=0;i--){
        if(i-y*x>=0 &&  ans > (prefix[i] - prefix[i-y*x])){
            ans = (prefix[i] - prefix[i-y*x]);
        }
    }
    return ans;

}
int main(){
    int n , x , y;
    cin>>n>>x>>y;
    vector<int>A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solution(A , x , y)<<endl;
    return 0;
}