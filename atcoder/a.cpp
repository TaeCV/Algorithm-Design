#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int H[N], M[N];
    for (int i = 0; i < N; ++i)
        cin >> H[i];
    M[0] = 0, M[1] = abs(H[1] - H[0]);
    for (int i = 2; i < N; ++i)
        M[i] = min(M[i - 1] + abs(H[i] - H[i - 1]), M[i - 2] + abs(H[i] - H[i - 2]));
    cout << M[N - 1];
}