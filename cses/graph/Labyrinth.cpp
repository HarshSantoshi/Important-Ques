#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> dirX = {1, 0, -1, 0}; 
vector<int> dirY = {0, -1, 0, 1}; 
vector<char> dirChar = {'D', 'L', 'U', 'R'}; 

string bfs(int startX, int startY, vector<vector<char>>& graph, vector<vector<int>>& vis, int destX, int destY) {
    queue<pair<int, int>> q;
    vector<vector<pair<int, char>>> parent(graph.size(), vector<pair<int, char>>(graph[0].size(), {-1, '#'})); 
    
    q.push({startX, startY});
    vis[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == destX && y == destY) {
            string path;
            while (x != startX || y != startY) {
                int px = parent[x][y].first;
                char move = parent[x][y].second;
                path += move;
                if (move == 'D') {
                    x--;
                } else if (move == 'L') {
                    y++;
                } else if (move == 'U') {
                    x++;
                } else if (move == 'R') {
                    y--;
                }
            }
            reverse(path.begin(), path.end()); 
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (newX >= 0 && newY >= 0 && newX < graph.size() && newY < graph[0].size() && graph[newX][newY] != '#' && !vis[newX][newY]) {
                vis[newX][newY] = 1;
                q.push({newX, newY});
                parent[newX][newY] = {x, dirChar[i]}; 
            }
        }
    }

    return "";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> graph(n, vector<char>(m));

    int startX = 0, startY = 0;
    int destX = 0, destY = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            if (graph[i][j] == 'B') {
                destX = i;
                destY = j;
            }
        }
    }

    string ans = bfs(startX, startY, graph, vis, destX, destY);

    if (ans.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    return 0;
}
