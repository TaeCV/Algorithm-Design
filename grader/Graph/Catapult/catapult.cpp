#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges, edges_T;
vector<int> order;
vector<bool> visited;
int N, M, x;

void dfs1(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    for (int v : edges_T[u]) {
        if (!visited[v])
            dfs1(v);
    }
    order.push_back(u);
}

int dfs2(int u) {
    visited[u] = true;
    int count = 1;
    for (int v : edges[u]) {
        if (!visited[v]) {
            count += dfs2(v);
        }
    }
    return count;
}

int main() {
    cin >> N;
    edges = vector<vector<int>>(N);
    edges_T = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    for (int i = 0; i < N; ++i) {
        cin >> M;
        for (int j = 0; j < M; ++j) {
            cin >> x;
            edges[i].push_back(x);
            edges_T[x].push_back(i);
        }
    }
    for (int i = 0; i < N; ++i)
        dfs1(i);
    visited = vector<bool>(N, false);
    vector<int> ans;
    for (int i = order.size() - 1; i >= 0; --i) {
        if (!visited[order[i]]) {
            ans.push_back(dfs2(order[i]));
        }
    }
    sort(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << " ";
}