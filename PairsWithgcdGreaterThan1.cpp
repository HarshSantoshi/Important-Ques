#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MAXN = 100005;

long Count_sol (int N, vector<int> A, vector<int> B) {
    vector<long> dp(MAXN, 0);
    unordered_map<int, int> mpA;
    unordered_map<int, int> mpB;
    
    for(int i = 0; i < N; i++) {
        mpA[A[i]]++;
        mpB[B[i]]++;
    }
    
    long ans = 0;
    for(int i = 100000; i >= 2; --i) {
        int c = 0;
        int d = 0;
        int s = 0;
        
        for(int j = i; j <= 100000; j += i) {
            c += mpA[j];
            d += mpB[j];
            s += dp[j];
        }
        
        long pw = (long)c * d;
        pw -= s;
        ans += pw;
        dp[i] = pw;
    }
    
    return ans;
}
int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {3, 6, 9};
    
    int N = arr1.size();
    int pairsCount = Count_sol(N ,arr1, arr2);
    
    cout << "Number of pairs with GCD > 1: " << pairsCount << endl;
    
    return 0;
}