#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int P[n + 1], M[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> P[i];
    for (int i = 1; i <= n; ++i) {
        M[i] = P[i];
        for (int j = 1; j < i; ++j)
            M[i] = max(M[i], M[j] + P[i - j]);
    }
    cout << M[n];
}