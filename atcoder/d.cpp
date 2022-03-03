#include <bits/stdc++.h>

using namespace std;

int N, W, Wi[101], Vi[101];
long long K[101][100001];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; ++i)
        cin >> Wi[i] >> Vi[i];
    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (Wi[i] <= w) {
                K[i][w] = max(K[i - 1][w - Wi[i]] + Vi[i], K[i - 1][w]);
            } else
                K[i][w] = K[i - 1][w];
        }
    }
    cout << K[N][W];
}