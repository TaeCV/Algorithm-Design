#include "stdio.h"
int min(int a, int b) { return a < b ? a : b; }
int N, M, width, newWidth, DP[2][10005], area, areaLeft, now, prev;
const int INT_MAX = 2147483647;

int main() {
    scanf("%d%d", &N, &M);
    prev = 0, now = 1;
    for (int i = 1; i <= M; ++i) {
        DP[prev][i] = INT_MAX;
    }
    DP[prev][0] = 0;
    while (N--) {
        scanf("%d", &width);
        for (area = M; area >= 0; --area) {
            DP[now][area] = INT_MAX;
            for (newWidth = 1; newWidth <= 100; ++newWidth) {
                areaLeft = area - newWidth * newWidth;
                if (areaLeft < 0)
                    break;
                if (DP[prev][areaLeft] < INT_MAX)
                    DP[now][area] = min(DP[now][area], DP[prev][areaLeft] + (newWidth - width) * (newWidth - width));
            }
        }
        prev ^= 1, now ^= 1;
    }
    printf("%d", DP[prev][M] == INT_MAX ? -1 : DP[prev][M]);
}