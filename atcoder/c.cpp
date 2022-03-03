#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A, B, C, M[2][3];
    cin >> M[0][0] >> M[0][1] >> M[0][2];
    int prev = 0, now = 1;
    for (int i = 1; i < N; ++i) {
        cin >> A >> B >> C;
        M[now][0] = max(M[prev][1], M[prev][2]) + A;
        M[now][1] = max(M[prev][0], M[prev][2]) + B;
        M[now][2] = max(M[prev][0], M[prev][1]) + C;
        now ^= 1, prev ^= 1;
    }
    cout << max(M[prev][0], max(M[prev][1], M[prev][2]));
}