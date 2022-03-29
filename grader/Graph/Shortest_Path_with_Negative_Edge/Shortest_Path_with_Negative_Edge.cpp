#include <bits/stdc++.h>

using namespace std;

int N, E, s, a, b, c;

const int inf = 1e6;

int main() {
    cin >> N >> E >> s;
    vector<vector<pair<int, int>>> edges(N);
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;
        edges[b].emplace_back(a, c);
    }
    vector<int> d(N, inf);
    d[s] = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int u = 0; u < N; ++u) {
            for (auto v : edges[u]) {
                if (v.second + d[v.first] < d[u]) {
                    d[u] = v.second + d[v.first];
                }
            }
        }
    }
    bool isNegCycle = false;
    for (int u = 0; u < N; ++u) {
        for (auto v : edges[u]) {
            if (v.second + d[v.first] < d[u]) {
                isNegCycle = true;
                break;
            }
        }
        if (isNegCycle)
            break;
    }
    if (!isNegCycle)
        for (auto x : d)
            cout << x << " ";
    else
        cout << "-1";
}