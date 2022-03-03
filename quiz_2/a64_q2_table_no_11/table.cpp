#include <bits/stdc++.h>

using namespace std;

const long long MOD = 100000007;

int main() {
    int N;
    cin >> N;
    int M[N][2];
    M[0][0] = 1;
    M[0][1] = 2;
    M[1][0] = 3;
    M[1][1] = 4;
    for (int i = 2; i < N; ++i) {
        M[i][0] = (M[i - 1][0] + M[i - 1][1]) % MOD;
        M[i][1] = ((M[i - 1][0] * 2) % MOD + M[i - 1][1]) % MOD;
    }
    cout << (M[N - 1][0] + M[N - 1][1]) % MOD;
}