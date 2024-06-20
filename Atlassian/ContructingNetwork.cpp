#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int findUparent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUparent(parent[node]);
    }
    
    bool unionByRank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        
        if (ulp_u == ulp_v) {
            return true;
        }
        
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return false;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    
    DisjointSet ds(n);
    int sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    
    vector<pair<int, int>> nums(e);
    for (int i = 0; i < e; ++i) {
        cin >> nums[i].first >> nums[i].second;
    }
    
    vector<int> ans;
    
    for (int i = 0; i < e; ++i) {
        int a = nums[i].first;
        int b = nums[i].second;
        
        if (ds.unionByRank(a, b)) {
            ans.push_back(sum);
        } else {
            sum -= min(a, b);
            ans.push_back(sum);
        }
    }
    
    for (auto c : ans) {
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}