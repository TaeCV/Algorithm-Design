#include <bits/stdc++.h>

using namespace std;

int DP[505][505];

int main() {
    string A, B;
    cin >> A >> B;
    int NA = A.size(), NB = B.size();
    for (int i = 1; i <= NA; ++i) {
        for (int j = 1; j <= NB; ++j) {
            if (A[NA - i] == B[NB - j]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    cout << DP[NA][NB];
}
