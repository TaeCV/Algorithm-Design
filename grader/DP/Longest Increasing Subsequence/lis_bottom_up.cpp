#include "stdio.h"

int N, A[1005], M[1005], ans;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        A[i] = 1;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M[i]);
        for (int j = 0; j < i; ++j) {
            if (M[j] < M[i])
                A[i] = A[j] + 1 > A[i] ? A[j] + 1 : A[i];
        }
    }
    ans = A[0];
    for (int i = 1; i < N; ++i)
        ans = A[i] > ans ? A[i] : ans;
    printf("%d", ans);
}