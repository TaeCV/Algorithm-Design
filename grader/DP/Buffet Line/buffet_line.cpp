#include <bits/stdc++.h>

using namespace std;

int N, K, M, p, w, DP[200005], l, r, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> DP[i];
        DP[i] += DP[i - 1] - M;
    }
    while (K--) {
        cin >> p >> w;
        w %= DP[N];
        if (DP[N] - DP[p - 1] < w) {
            l = 1, r = p - 1, m;
            while (l < r) {
                m = (l + r) >> 1;
                if (DP[m] < w)
                    l = m + 1;
                else {
                    r = m;
                }
            }
        } else {
            l = p, r = N;
            while (l < r) {
                m = (l + r) >> 1;
                if (DP[m] - DP[p - 1] < w)
                    l = m + 1;
                else
                    r = m;
            }
        }
        cout << l << "\n";
    }
}