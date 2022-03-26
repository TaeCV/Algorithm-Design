#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c, T, x, y;
    cin >> r >> c >> T;
    vector<vector<int>> M(r, vector<int>(c));
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> M[i][j];
            if (M[i][j] == 1) {
                q.push({i, j});
                cnt++;
            } else if (M[i][j] == 2) {
                M[i][j] = INT_MAX;
            }
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (auto d : dir) {
            x = now.first + d.first;
            y = now.second + d.second;
            if (x < 0 || x >= r || y < 0 || y >= c)
                continue;
            if (M[x][y] == 0) {
                M[x][y] = M[now.first][now.second] + 1;
                cnt++;
                if (M[x][y] <= T)
                    q.push({x, y});
            }
        }
    }
    cout << cnt;
}