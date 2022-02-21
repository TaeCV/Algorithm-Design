#include <bits/stdc++.h>

using namespace std;

int N, M, V[505], W[505], DP[505][505];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> V[i];
    for (int i = 1; i <= N; ++i)
        cin >> W[i];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            cin >> DP[i][j];
        }
    }
    int a = N, b = M;
    vector<int> ans;
    while (a > 0 && b > 0) {
        if (b >= W[a] && DP[a - 1][b] <= DP[a - 1][b - W[a]] + V[a]) {
            ans.push_back(a);
            b -= W[a];
        }
        --a;
    }
    cout << ans.size() << "\n";
    for (int &x : ans)
        cout << x << " ";
}