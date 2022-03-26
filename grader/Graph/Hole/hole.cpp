#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, a, b, x, y, mxX, mnX, mxY, mnY;
    cin >> N >> a >> b;
    mxX = a, mnX = a, mxY = b, mnY = b;
    vector<vector<bool>> M(1001, vector<bool>(1001, false));
    vector<vector<int>> dist(1001, vector<int>(1001, INT_MAX));
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        M[x][y] = true;
        mxX = max(mxX, x);
        mnX = min(mnX, x);
        mxY = max(mxY, y);
        mnY = min(mnY, y);
    }
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    queue<pair<int, int>> q;
    q.push({a, b});
    int ans = INT_MAX;
    dist[a][b] = 0;
    if (a == mnX || a == mxX || b == mnY || b == mxY)
        ans = min(ans, dist[x][y]);
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (auto d : dir) {
            x = now.first + d.first;
            y = now.second + d.second;
            if (x < 1 || x > 1000 || y < 1 || y > 1000)
                continue;
            if (M[x][y]) {
                if (dist[now.first][now.second] + 1 < dist[x][y]) {
                    dist[x][y] = min(dist[x][y], dist[now.first][now.second] + 1);
                    q.push({x, y});
                }
            } else if (dist[now.first][now.second] < dist[x][y]) {
                dist[x][y] = dist[now.first][now.second];
                q.push({x, y});
            }
            if (x == mnX || x == mxX || y == mnY || y == mxY)
                ans = min(ans, dist[x][y]);
        }
    }
    for (int i = mnX; i <= mxX; ++i) {
        for (int j = mnY; j <= mxY; ++j)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
    cout << ans;
}