#include <bits/stdc++.h>

using namespace std;

int n, e, k;
vector<vector<int>> edges;
vector<bool> visited;
vector<int> dist;

int bfs(int u) {
    queue<int> q;
    visited[u] = true;
    q.push(u);
    dist[u] = 0;
    int count = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int adj : edges[v]) {
            if (!visited[adj]) {
                visited[adj] = true;
                dist[adj] = dist[v] + 1;
                count++;
                if (dist[adj] < k)
                    q.push(adj);
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> e >> k;
    int a, b;
    edges = vector<vector<int>>(n);
    while (e--) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        visited = vector<bool>(n);
        dist = vector<int>(n, -1);
        ans = max(ans, bfs(i));
    }
    cout << ans;
}