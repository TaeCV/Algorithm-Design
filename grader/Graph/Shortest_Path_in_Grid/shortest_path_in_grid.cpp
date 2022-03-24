#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> maze;
vector<vector<bool>> visited;
vector<vector<int>> dist;
vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    cin >> r >> c;
    char x;
    maze = vector<vector<char>>(r + 1, vector<char>(c + 1, ' '));
    visited = vector<vector<bool>>(r + 1, vector<bool>(c + 1, false));
    dist = vector<vector<int>>(r + 1, vector<int>(c + 1, -1));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> maze[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;
    visited[1][1] = true;
    while (!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop();
        for (auto &d : dir) {
            int newX = coor.first + d.first, newY = coor.second + d.second;
            if (newX <= 0 || newX > r || newY <= 0 || newY > c)
                continue;
            if (maze[newX][newY] == '.' && !visited[newX][newY]) {
                q.push({newX, newY});
                dist[newX][newY] = dist[coor.first][coor.second] + 1;
                visited[newX][newY] = true;
            }
        }
    }
    cout << dist[r][c];
}