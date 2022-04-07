#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int n, m, k, flag, a, b, weight;

const int MAX_W = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> flag;
    vector<int> starter(k);
    vector<vector<ii>> edges(n);
    for (int i = 0; i < k; ++i)
        cin >> starter[i];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> weight;
        edges[b].push_back({a, weight});
    }
    int ans = MAX_W;
    vector<int> d(n, MAX_W);
    d[flag] = 0;
    bool isChange = false;
    for (int i = 0; i < n - 1; ++i) {
        // All edges
        for (int u = 0; u < n; ++u) {
            for (auto v : edges[u]) {
                if (d[u] + v.second < d[v.first]) {
                    d[v.first] = d[u] + v.second;
                    isChange = true;
                }
            }
        }
        if (!isChange)
            break;
    }
    for (int i = 0; i < k; ++i)
        ans = min(ans, d[starter[i]]);
    cout << ans;
}