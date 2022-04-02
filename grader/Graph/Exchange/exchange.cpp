#include <stdio.h>
int N, K;
double R[500][500];
bool solve() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%lf", &R[i][j]);
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                R[i][j] = R[i][k] * R[k][j] > R[i][j] ? R[i][k] * R[k][j] : R[i][j];
                if (i == j && R[i][j] > 1)
                    return true;
            }
    return false;
}

int main() {
    scanf("%d", &K);
    while (K--) {
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
}