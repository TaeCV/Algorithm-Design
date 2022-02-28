#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, P[10000], M[10000];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        M[i] = P[i];
    }
    for (int i = K + 1; i <= N - 1; ++i) {
        M[i] = M[i - 1] + P[i];
        for (int j = 2; j <= 2 * K + 1; ++j) {
            if (i - j < 0)
                break;
            M[i] = min(M[i], M[i - j] + P[i]);
        }
    }
    int ans = M[N - 1];
    for (int i = N - 1; i >= max(0, N - K - 1); --i)
        ans = min(ans, M[i]);
    cout << ans;
}