#include "stdio.h"

int n, m, x, diff, A[20], M[10005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        M[A[i]] = 1;
    }
    for (int i = 1; i <= 10000; ++i) {
        if (!M[i]) {
            for (int j = 0; j < n; ++j) {
                diff = i - A[j];
                if (diff >= 1 && M[diff]) {
                    M[i] = (M[i] == 0 || M[i] > (1 + M[diff])) ? 1 + M[diff] : M[i];
                }
            }
        }
    }
    printf("%d", M[m]);
}