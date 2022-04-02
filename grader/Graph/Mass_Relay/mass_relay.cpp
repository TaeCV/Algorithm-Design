#include <bits/stdc++.h>

using namespace std;

vector<int> p, ans;
vector<bool> visited;
int N, M, Q, D;

int findSet(int u) {
    return p[u] == u ? u : p[u] = findSet(p[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> Q;
    pair<int, pair<int, int>> dist[M];
    p = vector<int>(N);
    ans = vector<int>(N);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    for (int i = 0; i < M; ++i)
        cin >> dist[i].second.first >> dist[i].second.second >> dist[i].first;
    sort(dist, dist + M);
    for (int i = 0; i < M; ++i) {
        int u = dist[i].second.first, v = dist[i].second.second, w = dist[i].first;
        u = findSet(u), v = findSet(v);
        if (u != v) {
            p[u] = v;
            ans[--N] = w;
        }
    }
    while (Q--) {
        cin >> D;
        cout << ans[D] << "\n";
    }
}