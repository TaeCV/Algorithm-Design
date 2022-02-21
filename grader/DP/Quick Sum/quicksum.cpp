#include <bits/stdc++.h>

using namespace std;

int N, M, K, P[1005][1005], r1, r2, c1, c2;

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> P[i][j];
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }
    while (K--) {
        cin >> r1 >> c1 >> r2 >> c2;
        ++r1, ++c1, ++r2, ++c2;
        cout << P[r2][c2] - P[r2][c1 - 1] - P[r1 - 1][c2] + P[r1 - 1][c1 - 1] << "\n";
    }
}