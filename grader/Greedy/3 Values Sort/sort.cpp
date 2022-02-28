#include "stdio.h"
int min(int a, int b) { return a < b ? a : b; }
int abs(int x) { return x < 0 ? -x : x; }

int N, C[3], M[3][3];

int main() {
    scanf("%d", &N);
    int S[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &S[i]);
        C[S[i] - 1]++;
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            M[i][j] = 0;
    int idx = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < C[i]; ++j)
            M[i][S[idx++] - 1]++;
    printf("%d", min(M[0][1], M[1][0]) + abs(M[0][1] - M[1][0]) * 2 + min(M[0][2], M[2][0]) + min(M[1][2], M[2][1]));
}
