#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;

bool dfs(int u, int from) {
    visited[u] = true;
    int cnt = 0;
    for (int v : edges[u]) {
        if (v != from) {
            if (visited[v])
                return false;
            if (!visited[v]) {
                cnt++;
                if (cnt == 2 || !dfs(v, u))
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int v, e, a, b;
    cin >> v >> e;
    edges = vector<vector<int>>(v);
    visited = vector<bool>(v, false);
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < v; ++i) {
        if (!visited[i] && edges[i].size() <= 1) {
            ans += dfs(i, -1);
        }
    }
    cout << ans;
}