#include "stdio.h"
int N, M, K, DP[2][35][35], now, prev;

int main() {
    scanf("%d%d%d", &N, &M, &K);
    now = 1, prev = 0;
    DP[0][1][0] = 1;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 1; j <= M; ++j)
            for (int k = 0; k <= K; ++k)
                DP[now][j][k] = 0; // Reset before the collect data

        for (int j = 1; j <= M; ++j) {
            for (int k = 0; k <= K; ++k) {
                DP[now][j + 1][k] = DP[prev][j][k];  // use the same number from last line
                DP[now][1][k + 1] += DP[prev][j][k]; // use another number from last line
            }
        }
        now ^= 1, prev ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= M; ++i)
        ans += DP[prev][i][K];
    printf("%d", ans);
}
