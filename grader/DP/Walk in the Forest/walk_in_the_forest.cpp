#include <bits/stdc++.h>

using namespace std;

int N, M, A[505][505];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
            if (i > 1 && j > 1) {
                A[i][j] = max(max(A[i][j] * 2 + A[i - 1][j - 1], A[i][j] + A[i - 1][j]), A[i][j] + A[i][j - 1]);
            } else if (i > 1) {
                A[i][j] += A[i - 1][j];
            } else if (j > 1) {
                A[i][j] += A[i][j - 1];
            }
        }
    cout << A[N][M];
}