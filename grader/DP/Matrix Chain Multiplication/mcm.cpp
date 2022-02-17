#include <bits/stdc++.h>

using namespace std;
int N, M[105], A[105][105];

int main() {
    cin >> N;
    for (int i = 0; i <= N; ++i)
        cin >> M[i];
    for (int j = 1; j < N; ++j) {
        for (int i = 0; i < N - j; ++i) {
            for (int a = 0; a < j; ++a) {
                A[i][i + j] = A[i][i + j] == 0 ? A[i][i + a] + A[i + a + 1][i + j] + M[i] * M[i + a + 1] * M[i + j + 1] : min(A[i][i + j], A[i][i + a] + A[i + a + 1][i + j] + M[i] * M[i + a + 1] * M[i + j + 1]);
            }
        }
    }
    cout << A[0][N - 1];
}