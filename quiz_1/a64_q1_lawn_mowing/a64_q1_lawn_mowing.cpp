#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long N, M, K, a, b, mx, l, r, tmp;
    cin >> N >> M >> K;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    while (M--) {
        bool isAnswer = false;
        cin >> a >> b;
        l = a + 1, r = N;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (A[m] - A[a] + (m - a) * K <= b)
                l = m;
            else {
                r = m - 1;
            }
        }
        cout << (A[r] - A[a] + (r - l + 1) * K <= b ? A[r] - A[a] : 0) << "\n";
    }
}

/*
5 5 0
1 2 3 4 5
1 5
1 8
1 9
1 10
1 14

5 4 2
1 1 1 1 1
0 2
0 5
0 10
0 1000
*/