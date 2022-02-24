#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, T[100000], S[100];
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> T[i];
    sort(T, T + M);
    double total = 0;
    int a = M / N, b = M % N, c = -1;
    for (int i = 0; i < M; ++i) {
        if (i % N == 0)
            ++c;
        total += T[i] * (a - c);
        if (i % N < b)
            total += T[i];
    }
    printf("%.3lf", total / M);
}