#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int H, W, dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    char c;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> c;
            if (c == '.') {
                if (i == 1 && j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[H][W];
}