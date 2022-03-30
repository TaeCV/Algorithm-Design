#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<int, iii> iv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    cin >> R >> C;
    int M[R][C];
    vector<vector<vector<int>>> d = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(3, 1e9)));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> M[i][j];
    d[0][0][0] = 0;                                 // no eliz left
    d[0][0][1] = 0;                                 // has 1 eliz left
    d[0][0][2] = 0;                                 // has 2 eliz left
    priority_queue<iv, vector<iv>, greater<iv>> pq; // first = weight, second = r, thrid = c, fourth = eliz left
    pq.push({0, {{0, 0}, 2}});
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<ii> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<ii> dirOfEliz = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-2, 0}, {0, -2}, {2, 0}, {0, 2}};
    while (!pq.empty()) {
        iv u = pq.top();
        pq.pop();
        int nowX = u.second.first.first, nowY = u.second.first.second, eliz = u.second.second;
        for (auto coor : dir) {
            int x = nowX + coor.first;
            int y = nowY + coor.second;
            if (x < 0 || x >= R || y < 0 || y >= C)
                continue;
            if (d[x][y][eliz] > M[x][y] + d[nowX][nowY][eliz]) {
                d[x][y][eliz] = M[x][y] + d[nowX][nowY][eliz];
                pq.push({d[x][y][eliz], {{x, y}, eliz}});
            }
        }
        if (eliz > 0)
            for (auto coor : dirOfEliz) {
                int x = nowX + coor.first;
                int y = nowY + coor.second;
                if (x < 0 || x >= R || y < 0 || y >= C)
                    continue;
                if (d[x][y][eliz - 1] > d[nowX][nowY][eliz]) {
                    d[x][y][eliz - 1] = d[nowX][nowY][eliz];
                    pq.push({d[x][y][eliz - 1], {{x, y}, eliz - 1}});
                }
            }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j)
            cout << d[i][j][0] << " ";
        cout << '\n';
    }
}