#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e6;
    int bFoundRabinKarp(string src , string dest){
        if(src == "" || dest == "")return -1;
        int len = dest.length();
        int power = 1;
        for(int i=0;i<len;i++){
            power = (power*31)%mod;
        }
        int destCode = 0;
        for(int i=0;i<len;i++){
            destCode = (destCode*31 + dest[i])%mod;
        }
        int srcCode = 0;
        for(int i=0;i<src.length();i++){
            srcCode = (srcCode*31 + src[i])%mod;
            if(i<len-1){
                continue;
            }
            if(i>=len){
                srcCode = (srcCode - src[i-len]*power)%mod;
            }
            if(srcCode < 0){
                srcCode += mod;
            }
            if(srcCode == destCode){
                if(src.substr(i-len+1 , len) == dest){
                    return 1;
                }
            }
        }
        return -1;

    }
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        int count = 1;
        string src = a;
        while(src.length()<m){
            count ++ ;
            src+=a;
        }
        if(bFoundRabinKarp(src , b)!=-1)return count ;
        src+= a;
        if(bFoundRabinKarp(src  , b)!=-1)return count + 1 ;
        return -1;
    }

};