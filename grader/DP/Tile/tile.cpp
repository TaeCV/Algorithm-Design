#include <bits/stdc++.h>

using namespace std;

int N, M, width, DP[15][10005], area, areaLeft;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        DP[0][i] = INT_MAX;
    }
    for (int i = 1; i <= N; ++i) {
        DP[i][0] = INT_MAX;
    }
    for (int piece = 1; piece <= N; ++piece) {
        cin >> width;
        for (area = M; area > 0; --area) {
            DP[piece][area] = INT_MAX;
            for (int newWidth = 1; newWidth <= 100; ++newWidth) {
                areaLeft = area - newWidth * newWidth;
                if (areaLeft < 0)
                    break;
                if (DP[piece - 1][areaLeft] < INT_MAX)
                    DP[piece][area] = min(DP[piece][area], DP[piece - 1][areaLeft] + (newWidth - width) * (newWidth - width));
            }
        }
    }
    cout << (DP[N][M] == INT_MAX ? -1 : DP[N][M]);
}