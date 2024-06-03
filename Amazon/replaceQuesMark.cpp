#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;



int main() {
    string s;
    cin>>s;
    int n = s.length();
    char prev = '2';
    for(int i=0;i<n;i++){
        if(s[i] == '?'){
            s[i] = prev;
        }
        prev = s[i];
    }
    for(int i=n-1;i>=0;i--){
        if(s[i] == '2'){
            s[i] = prev;
        }
        prev = s[i];
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    cout<<s<<endl;
    cout<<ans<<endl;
    return 0;
}