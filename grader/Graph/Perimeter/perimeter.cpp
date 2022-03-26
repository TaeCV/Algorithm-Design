#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<int> dist;
vector<bool> visited;

int main() {
    int n, e, k, a, b;
    cin >> n >> e >> k;
    edges = vector<vector<int>>(n + 1);
    dist = vector<int>(n + 1);
    visited = vector<bool>(n + 1, false);
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    queue<int> q;
    dist[0] = 0;
    visited[0] = true;
    q.push(0);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : edges[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                if (dist[v] < k)
                    q.push(v);
                else if (dist[v] == k)
                    cnt++;
            }
        }
    }
    cout << cnt;
}