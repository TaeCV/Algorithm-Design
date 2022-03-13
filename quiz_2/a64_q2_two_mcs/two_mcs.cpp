#include <bits/stdc++.h>

using namespace std;

int N;
int A[500001], ML[500001], MR[500002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1, s = 0; i <= N; ++i) {
        cin >> A[i];
        s += A[i];
        ML[i] = max(ML[i - 1], s);
        s = max(s, 0);
    }
    for (int i = N, s = 0; i >= 1; --i) {
        s += A[i];
        MR[i] = max(MR[i + 1], s);
        s = max(s, 0);
    }
    int ans = ML[N];
    for (int i = 1; i <= N; ++i)
        ans = max(ans, ML[i] + MR[i + 1]);
    cout << ans;
}