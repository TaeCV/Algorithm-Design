#include "stdio.h"

int N, A[1005], x, ans, l, r, m, pos;

int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        if (ans == 0 || x >= A[ans - 1])
            A[ans++] = x;
        else {
            l = 0, r = ans - 1, pos = 0;
            while (l <= r) {
                m = (l + r + 1) >> 1;
                if (x >= A[m])
                    l = m + 1;
                else {
                    pos = m;
                    r = m - 1;
                }
            }
            A[pos] = x;
        }
    }
    printf("%d", ans);
}