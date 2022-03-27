#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, e, a, b;
    cin >> n >> e;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        edges[b].push_back(a);
    }
    vector<bool> visited;
    for (int i = 0; i < 5; ++i) {
        visited = vector<bool>(n + 1, false);
        bool isFail = false;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            visited[a] = true;
            if (isFail)
                continue;
            for (int pre : edges[a]) {
                if (!visited[pre]) {
                    isFail = true;
                    break;
                }
            }
        }
        cout << (isFail ? "FAIL\n" : "SUCCESS\n");
    }
}