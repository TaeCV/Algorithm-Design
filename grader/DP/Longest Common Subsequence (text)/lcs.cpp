#include <bits/stdc++.h>

using namespace std;

int N, M, L[1005][1005];
string X, Y, ans = "";

int main() {
    cin >> N >> M;
    cin >> X;
    cin >> Y;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            cin >> L[i][j];
        }
    }
    int x = N, y = M;
    while (x > 0 && y > 0) {
        if (X[x - 1] == Y[y - 1]) {
            ans = X[x - 1] + ans;
            --x, --y;
        } else if (L[x - 1][y] <= L[x][y - 1]) {
            --y;
        } else {
            --x;
        }
    }
    cout << ans;
}