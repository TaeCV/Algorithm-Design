#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, a, b;
    cin >> N >> M >> K;
    vector<int> d(N, 1e9), cost(N), init(K);
    for (int i = 0; i < K; ++i)
        cin >> init[i];
    for (int i = 0; i < N; ++i)
        cin >> cost[i];
    vector<vector<int>> edges(N);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int ans = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<bool> visited(N, false);
    for (int x : init) {
        d[x] = cost[x];
        pq.push({d[x], x});
    }
    while (!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if (!visited[u.second]) {
            ans = max(ans, u.first);
            visited[u.second] = true;
            for (int v : edges[u.second])
                if (!visited[v] && d[u.second] + cost[v] < d[v]) {
                    d[v] = d[u.second] + cost[v];
                    pq.push({d[v], v});
                }
        }
    }
    cout << ans;
}