#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D;
    scanf("%d%d", &N, &D);
    int P[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &P[i]);
    int count, now, peak = P[N - 1], i;
    auto it = upper_bound(P, P + N, peak / D);
    count = 0, now = 0, i = 0;
    while (now < peak) {
        ++count;
        while (i < N && P[i] <= now + *it)
            ++i;
        now = P[--i];
    }
    printf("%d %d", *it, count);
}