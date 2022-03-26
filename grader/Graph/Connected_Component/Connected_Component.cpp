#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : edges[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int v, e, a, b;
    cin >> v >> e;
    edges = vector<vector<int>>(v + 1);
    visited = vector<bool>(v + 1, false);
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}