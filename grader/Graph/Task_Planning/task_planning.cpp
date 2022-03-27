#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> E;
vector<int> ans;

void dfs(int u) {
    visited[u] = true;
    for (int v : E[u])
        if (!visited[v])
            dfs(v);
    ans.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, a;
    cin >> N;
    E = vector<vector<int>>(N);
    for (int i = 0; i < N; ++i) {
        cin >> M;
        E[i].resize(M);
        for (int j = 0; j < M; ++j) {
            cin >> E[i][j];
        }
    }
    visited = vector<bool>(N, false);
    for (int i = 0; i < N; ++i)
        if (!visited[i])
            dfs(i);
    for (int u : ans)
        cout << u << " ";
}