#include <bits/stdc++.h>

using namespace std;

int N, i, j, mx = INT_MIN, A[1005][1005];

int main() {
    cin >> N;
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            cin >> A[i][j];
            A[i][j] = max(A[i][j], A[i][j] + A[i - 1][j - 1]);
            mx = max(mx, A[i][j]);
        }
    }
    cout << mx;
}