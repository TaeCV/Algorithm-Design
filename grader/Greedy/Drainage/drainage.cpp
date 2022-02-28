#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L;
    scanf("%d%d", &N, &L);
    int P[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &P[i]);
    sort(P, P + N);
    int i = 0, count = 0, now;
    while (i < N) {
        ++count;
        now = P[i];
        while (i < N && P[i] < now + L)
            ++i;
    }
    cout << count;
}