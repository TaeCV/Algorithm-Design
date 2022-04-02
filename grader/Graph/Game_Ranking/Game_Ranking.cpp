#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges, edges_T;
vector<bool> visited;
vector<int> dt, ans, component, level;
int mx, mx_ans;

void dfs(int u) {
    visited[u] = true;
    for (int v : edges[u]) {
        if (!visited[v])
            dfs(v);
    }
    dt.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    component.push_back(u);
    for (int v : edges_T[u]) {
        if (!visited[v])
            dfs2(v);
        else
            mx = max(mx, level[v]);
    }
}

int main() {
    int N, P, winner, loser;
    cin >> N >> P;
    edges = vector<vector<int>>(N);
    edges_T = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    level = vector<int>(N);
    ans = vector<int>(N);
    for (int i = 0; i < P; ++i) {
        cin >> winner >> loser;
        edges[winner].push_back(loser);
        edges_T[loser].push_back(winner);
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i])
            dfs(i);
    }
    visited = vector<bool>(N, false);
    for (int i = N - 1; i >= 0; --i) {
        if (!visited[dt[i]]) {
            mx = 0;
            dfs2(dt[i]);
            for (int u : component) {
                level[u] = mx + 1;
            }
            ans[mx] += component.size();
            mx_ans = max(mx_ans, mx);
            component.clear();
        }
    }
    for (int i = 0; i <= mx_ans; ++i)
        cout << ans[i] << " ";
}