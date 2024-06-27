#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int result = 0;
    void solve(int idx, vector<int>& permutation, vector<bool>& visited ,int n,vector<int>&count, unordered_map<int, int>&mp ) {
            if (idx >= n) {
                if (isCorrect(n, count,mp)) {
                    result = (result + 1) % MOD;
                }
                return;
            }

            for (int num = 0; num < n; num++) {
                if (!visited[num]) {
                    visited[num] = true;
                    int add = 0;
                    for (int i = 0; i < idx; ++i) {
                        if (permutation[i] > num) {
                            add++;
                        }
                    }
                    permutation[idx] = num;
                    count[idx + 1] = count[idx] + add;
                    solve(idx + 1, permutation, visited, n , count , mp);
                    visited[num] = false;
                }
            }
        }
    bool isCorrect(int n, vector<int>& count, unordered_map<int, int>&mp) {
        for (auto it : mp) {
            int endi = it.first;
            int cnti = it.second;
            if (endi <= n && count[endi] != cnti) {
                return false;
            }
        }
        return true;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<vector<int>> dp(n + 1, vector<int>(402, 0));
        
        
        vector<int> count(n + 1, 0);
        vector<int> permutation(n, 0);
        vector<bool>visited(n, false);
        dp[0][0] = 1;
        for (int len = 1; len <= n; len++) {
            for (int k = 0; k <= 400; k++) {
                dp[len][k] = 0;
                for (int i = 0; i < len; ++i) {
                    if (k >= i) {
                        dp[len][k] = ( dp[len - 1][k - i] + dp[len][k] ) % MOD;
                    }
                }
            }
        }

        unordered_map<int, int>mp;
        for (auto it : requirements) {
            int idx = it[0]+ 1;
            mp[idx] = it[1];
        }
        
        solve(0, permutation, visited , n , count,mp);

        return result;
    }
};