#include <stdio.h>
#include <stdlib.h>

int n, m, k, A[100], ans = 1e9;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int min (const a,const b) {return a<b ? a : b;}

int sumLeft(int quota, int idx) {
    int sm = 0;
    for (int i = idx; i < n && quota > 0; ++i, quota--)
        sm += A[i];
    return sm;
}

void cal(int len, int sm, int quota) {
    if (len == n) {
        if (quota > 0)
            return;
        ans = min(abs(k - sm), ans);
    } else {
        if (abs(k - sm - sumLeft(quota, len)) > ans)
            return;
        if (quota > 0) {
            cal(len + 1, sm + A[len], quota - 1);
        }
        cal(len + 1, sm, quota);
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i)
        scanf("%d",&A[i]);
    qsort(A, n, sizeof(int), cmpfunc);
    cal(0, 0, m);
    printf("%d",ans);
}