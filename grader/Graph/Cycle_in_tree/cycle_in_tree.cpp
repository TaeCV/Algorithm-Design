#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
vector<int> from;
bool isDone = false;

void dfs(int u, int last) {
    visited[u] = true;
    for (int v : edges[u]) {
        if (isDone)
            continue;
        if (v != last) {
            if (!visited[v]) {
                from[v] = u;
                dfs(v, u);
            } else {
                // found a cycle
                int count = 1;
                int now = u;
                while (now != v) {
                    count++;
                    now = from[now];
                }
                cout << count;
                isDone = true;
            }
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    edges = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    from = vector<int>(n);
    bool isCycle = false;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        for (int tmp : edges[a])
            if (tmp == b)
                isCycle = true;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    if (isCycle)
        cout << "2";
    else
        dfs(0, -1);
}