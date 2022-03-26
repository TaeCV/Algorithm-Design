#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    while (K--) {
        int R, C, n, T, r, c, x, y;
        cin >> R >> C >> n >> T >> r >> c;
        int ri, ci, ti;
        vector<string> M(R); // MAP
        vector<vector<int>> TABLE(R, vector<int>(C, T + 1)), dist(R, vector<int>(C, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            cin >> ti >> ri >> ci;
            TABLE[ri][ci] = min(TABLE[ri][ci], ti);
            q.push({ri, ci});
        }
        for (int i = 0; i < R; ++i)
            cin >> M[i];
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            for (auto d : dir) {
                x = now.first + d.first;
                y = now.second + d.second;
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (M[x][y] == '.') {
                    if (TABLE[now.first][now.second] + 1 < TABLE[x][y]) {
                        TABLE[x][y] = TABLE[now.first][now.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        q.push({r, c});
        bool isSurvive = (TABLE[r][c] > T);
        while (!isSurvive && !q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            for (auto d : dir) {
                x = now.first + d.first;
                y = now.second + d.second;
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (M[x][y] == '.') {
                    if (TABLE[x][y] > T) {
                        isSurvive = true;
                        break;
                    }
                    if (dist[now.first][now.second] + 1 < TABLE[x][y] && dist[x][y] < dist[now.first][now.second] + 1) {
                        dist[x][y] = dist[now.first][now.second] + 1;
                        if (dist[x][y] >= T) {
                            isSurvive = true;
                            break;
                        }
                        q.push({x, y});
                    }
                }
            }
        }
        if (isSurvive)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}