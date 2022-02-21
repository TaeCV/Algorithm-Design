#include <bits/stdc++.h>

using namespace std;

long long N, M[10005][3], ans;

int main() {
    cin >> N;
    M[1][0] = 1;
    M[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        M[i][0] = (M[i - 1][0] + M[i - 1][2]) % 100000007;
        M[i][1] = (M[i - 1][0] + M[i - 1][1]) % 100000007;
        M[i][2] = M[i - 1][1] % 100000007;
    }
    for (int i = 0; i < 3; ++i)
        ans += M[N][i];
    cout << ans % 100000007;
}
