#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> e;
vector<bool> visited;
vector<int> d;

const int MAX_W = 1001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, ans = 0;
    cin >> N;
    visited = vector<bool>(N, false);
    d = vector<int>(N, MAX_W);
    e = vector<vector<int>>(N, vector<int>(N, MAX_W));
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1, c = 0; j < N; ++j) {
            cin >> e[i][j];
            e[j][i] = e[i][j];
        }
    }
    d[0] = 0;
    for (int i = 0; i < N; ++i) {
        int u = 0, mn = MAX_W;
        for (int j = 0; j < N; ++j)
            if (d[j] < mn)
                mn = d[j], u = j;
        ans += mn;
        d[u] = MAX_W;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && e[u][v] < d[v]) {
                d[v] = e[u][v];
            }
        }
    }
    cout << ans;
}