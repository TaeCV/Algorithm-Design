#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> edges(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> edges[i][j];
    int ans = 0;
    vector<int> d(N, 1e9);
    d[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        for (int v = 0; v < N; ++v)
            if (edges[u.second][v] > 0 && d[v] > u.first + edges[u.second][v]) {
                d[v] = u.first + edges[u.second][v];
                pq.push({d[v], v});
            }
    }
    bool isNotConnect = false;
    for (int i = 0; i < N; ++i) {
        if (d[i] == 1e9) {
            isNotConnect = true;
            break;
        }
        ans = max(ans, d[i]);
    }
    cout << (isNotConnect ? -1 : ans);
}