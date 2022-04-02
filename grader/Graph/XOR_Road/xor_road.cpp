#include <bits/stdc++.h>

using namespace std;

vector<int> p, h;

int findSet(int u) {
    return p[u] == u ? u : p[u] = findSet(p[u]);
}

void unionSet(int u, int v) {
    if (h[u] > h[v])
        p[v] = u;
    else {
        if (h[u] == h[v])
            h[v]++;
        p[u] = v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    int total_edges = (N * (N + 1)) / 2;
    pair<unsigned long long, pair<int, int>> edges[total_edges];
    int c = 0;
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            edges[c++] = {nums[i] ^ nums[j], {i, j}};
    sort(edges, edges + total_edges, greater<pair<int, pair<int, int>>>());
    p = vector<int>(N);
    h = vector<int>(N);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    unsigned long long ans = 0;
    for (auto e : edges) {
        unsigned long long w = e.first;
        int u = e.second.first, v = e.second.second;
        u = findSet(u), v = findSet(v);
        if (u != v) {
            unionSet(u, v);
            ans += w;
        }
    }
    cout << ans;
}