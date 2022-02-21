#include <bits/stdc++.h>

using namespace std;

int MOD = 1997, N, K, M[505][505];

int main() {
    cin >> N >> K;
    if (N < K)
        cout << 0;
    else {
        M[1][1] = 1;
        for (int i = 2; i <= N; ++i) {
            M[i][1] = 1;
            M[i][i] = 1;
            for (int j = 2; j < i; ++j) {
                M[i][j] = ((M[i - 1][j] * j) % MOD + M[i - 1][j - 1]) % MOD;
            }
        }
        cout << M[N][K];
    }
}