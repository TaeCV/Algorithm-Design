#include <bits/stdc++.h>

using namespace std;

bool gaa(int N, vector<int> &G, int k) {
    if (k == 3)
        return N == 1;
    if (N > G[k - 1] && N <= G[k - 1] + k) {
        return (N - G[k - 1]) == 1;
    }
    return (N <= G[k - 1]) ? gaa(N, G, k - 1) : gaa(N - G[k - 1] - k, G, k - 1);
}

int main() {
    int N, k = 2;
    cin >> N;
    vector<int> G(25);
    while (G[k] < N) {
        G[k + 1] = G[k] * 2 + k + 1, ++k;
    }
    cout << (gaa(N, G, k) ? "g" : "a");
}