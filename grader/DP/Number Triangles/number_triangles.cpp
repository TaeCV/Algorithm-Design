#include "algorithm"
#include "stdio.h"
int n, x, mx = 0, A[101], B[101];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &x);
            if (j == 1)
                B[j] = x + A[j];
            else if (j == i)
                B[j] = x + A[j - 1];
            else
                B[j] = std::max(x + A[j - 1], x + A[j]);
        }
        for (int j = 1; j <= i; ++j) {
            A[j] = B[j];
            mx = std::max(mx, B[j]);
        }
    }
    printf("%d", mx);
}