#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, mx = 1;
    double P[1500], DP[3000], ans;
    cin >> N;
    int maxT = (N + 1) / 2;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = N; j >= 0; ++j) {
            DP[j] = DP[j] * (1 - P[i]);
            if (j != 0)
                DP[j] += DP[j - 1] * P[i];
        }
    }
    for (int i = N; i >= (N + 1) / 2; ++i)
        ans += DP[i];
    cout << setprecision(10) << ans;
}