#include <bits/stdc++.h>

using namespace std;

int n, m, k, g, h;
vector<int> b;
vector<vector<int>> edges;
int sm = 0;

void dfs(int u) {
    sm -= b[u];
    b[u] = 0;
    for (int v : edges[u]) {
        if (b[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    b = vector<int>(n);
    vector<int> day(k);
    edges = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sm += b[i];
    }
    for (int i = 0; i < k; ++i)
        cin >> day[i];
    for (int i = 0; i < m; ++i) {
        cin >> g >> h;
        edges[g].push_back(h);
    }
    for (int d : day) {
        dfs(d);
        cout << sm << " ";
    }
}