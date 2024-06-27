#include<bits/stdc++.h>
using namespace std;
void generateLPS(vector<int>&lps , string target){
    int prefixIdx = 0 , suffixIdx = 1;
    while(suffixIdx<target.size()){
        if(target[prefixIdx] == target[suffixIdx]){
            lps[suffixIdx] = prefixIdx + 1;
            prefixIdx ++;
            suffixIdx ++;
        }
        else{
            if(prefixIdx == 0){
                lps[suffixIdx] = 0;
                suffixIdx++;
            }
            else{
                prefixIdx = lps[prefixIdx - 1];
            }
        }
    }
}
bool foundTargetInSrc(string src , string target){
    if(src == target)return 1;
    vector<int>LPS(target.size(),0);
    generateLPS(LPS , target);
    int srcIdx = 0 , targetIdx = 0 ;
    while(srcIdx < src.length() && targetIdx < target.length()){
        if(src[srcIdx] == target[targetIdx]){
            srcIdx++;
            targetIdx++;
        }
        else{
            if(targetIdx == 0){
                srcIdx++;
            }
            else{
                targetIdx = LPS[targetIdx - 1];
            }
        }
    }
    if(targetIdx == target.length())return 1;
    return 0;
}
int main(){
    string src ;
    string target;
    cin>>src>>target;
    if(foundTargetInSrc(src , target)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}