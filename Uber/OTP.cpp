#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int>rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};

int solve(vector<string>& v) {
    int n = v.size();
    DisjointSet ds(n);
    vector<int>prev(26, -1);
    for (int i = 0; i < n; ++i)
    {
        for (auto it : v[i]) {
            if (prev[it - 'a'] == i)continue;
            if (prev[it - 'a'] != -1)
                ds.unionBySize(i, prev[it - 'a']);
            prev[it - 'a'] = i;
        }
    }
    set<int>st;
    for (int i = 0; i < n; ++i)
    {
        int val = ds.findUPar(i);
        st.insert(val);
    }
    int res = st.size();
    return res;
}