#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;



int main() {
    int N;
    cin>>N;
    vector<int>A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int prev = 1;
    bool possible = true;
    A[0] = 1 ;
    for(int i=1;i<N;i++){
        if(A[i] <=  prev){
            possible = false;
        }
        else{
            A[i] = prev + 1;
            prev ++;
        }
    }
    if(possible){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}