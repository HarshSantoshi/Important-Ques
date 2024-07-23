#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> teams(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    for (int i = 1; i <= n; i++)
    {
        if (teams[i] == -1)
        {
            teams[i] = 1;
            queue<int> q;
            q.push(i);
            while (q.size())
            {
                int node = q.front();
                q.pop();
                for (auto neigh : adj[node])
                {
                    if (teams[neigh] == -1)
                    {
                        teams[neigh] = teams[node] == 1 ? 2 : 1;
                        q.push(neigh);
                    }
                    else if (teams[neigh] != teams[node])
                    {
                        continue;
                    }
                    else
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << teams[i] << " ";
    }
    cout << endl;
}