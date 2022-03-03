#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int H[N], M[N];
    for (int i = 0; i < N; ++i)
        cin >> H[i];
    M[0] = 0;
    for (int i = 1; i < N; ++i) {
        M[i] = M[i - 1] + abs(H[i] - H[i - 1]);
        for (int j = 2; j <= K && i - j >= 0; ++j) {
            M[i] = min(M[i], M[i - j] + abs(H[i] - H[i - j]));
        }
    }
    cout << M[N - 1];
}