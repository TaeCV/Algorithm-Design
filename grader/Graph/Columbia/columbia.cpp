#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> tri;
const int inf = 1e6;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> M(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> M[i][j];
        }
    }
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> d(R, vector<int>(C, inf));
    vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));
    d[0][0] = 0;
    priority_queue<tri, vector<tri>, greater<tri>> pq;
    pq.push({d[0][0], {0, 0}});
    while (!pq.empty()) {
        tri u = pq.top();
        pq.pop();
        int w = u.first, r = u.second.first, c = u.second.second;
        if (!visited[r][c]) {
            visited[r][c] = true;
            for (auto &coor : dir) {
                int x = r + coor.first, y = c + coor.second;
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (!visited[x][y] && d[r][c] + M[x][y] < d[x][y]) {
                    d[x][y] = d[r][c] + M[x][y];
                    pq.push({d[x][y], {x, y}});
                }
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j)
            cout << d[i][j] << ' ';
        cout << '\n';
    }
}