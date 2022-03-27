#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> tri;

priority_queue<tri, vector<tri>, greater<tri>> pq;
vector<int> P, H;

int findSet(int u) {
    if (u == P[u])
        return u;
    return findSet(P[u]);
}

void unionSet(int u, int v) {
    if (H[u] > H[v]) {
        P[v] = u;
    } else {
        P[u] = v;
        if (H[u] == H[v])
            H[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, w;
    cin >> N;
    P = vector<int>(N), H = vector<int>(N);
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> w;
            pq.push({w, {i, j}});
        }
    }
    for (int i = 0; i < N; ++i)
        P[i] = i;
    vector<pair<int, int>> E;
    int ans = 0;
    while (E.size() != N - 1) {
        auto candidate = pq.top();
        pq.pop();
        int w = candidate.first, u = candidate.second.first, v = candidate.second.second;
        int pU = findSet(u), pV = findSet(v);
        if (pU != pV) {
            ans += w;
            E.push_back({u, v});
            unionSet(pU, pV);
        }
    }
    cout << ans;
}