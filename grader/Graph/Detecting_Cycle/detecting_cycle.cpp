#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> edges;
vector<bool> visited;

bool dfs(int u, int from) {
    for (int v = 0; v < edges.size(); ++v) {
        if (edges[u][v] && v != from) {
            if (visited[v])
                return true;
            visited[v] = true;
            if (dfs(v, u))
                return true;
        }
    }
    return false;
}

bool cycle() {
    for (int i = 0; i < edges.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, e, a, b;
        cin >> n >> e;
        edges = vector<vector<bool>>(n, vector<bool>(n, false));
        visited = vector<bool>(n, false);
        while (e--) {
            cin >> a >> b;
            edges[a][b] = true;
            edges[b][a] = true;
        }
        if (cycle())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}