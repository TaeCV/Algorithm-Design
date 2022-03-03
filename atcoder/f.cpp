#include <bits/stdc++.h>

using namespace std;
string s, t;
int dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int ns = s.length(), nt = t.length();
    for (int i = 1; i <= ns; ++i) {
        for (int j = 1; j <= nt; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    int x = ns, y = nt;
    while (x > 0 && y > 0) {
        if (s[x - 1] == t[y - 1]) {
            ans = s[x - 1] + ans;
            --x, --y;
        } else if (dp[x - 1][y] > dp[x][y - 1]) {
            --x;
        } else {
            --y;
        }
    }
    cout << ans;
}