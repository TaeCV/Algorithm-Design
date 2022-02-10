#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, A, K;
    cin >> N >> A;
    vector<long long> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    while (A--) {
        cin >> K;
        long long L = 0, R = 1e18;
        while (L < R) {
            long long X = N, M = (L + R) / 2;
            for (long long &Ti : T) {
                X += M / Ti;
            }
            K <= X ? R = M : L = M + 1;
        }
        cout << R << "\n";
    }
}