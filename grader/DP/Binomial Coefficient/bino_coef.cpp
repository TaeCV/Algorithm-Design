#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int C[n + 1][n + 1];
    for (int i = 0; i <= n; ++i)
        C[i][0] = C[i][i] = 1;
    if (n == k || k == 0)
        cout << "1";
    else {
        for (int i = 2; i <= n; ++i) {
            for (int j = max(1, k - n + i); j < i && j <= k; ++j) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        cout << C[n][k];
    }
}