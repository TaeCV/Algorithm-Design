#include <bits/stdc++.h>

using namespace std;

int Wi[100], Vi[100];

int process(int idx, int weightLeft) {
    if (idx < 0 || weightLeft == 0)
        return 0;
    if (weightLeft < Wi[idx])
        return process(idx - 1, weightLeft);
    return max(Vi[idx] + process(idx - 1, weightLeft - Wi[idx]), process(idx - 1, weightLeft));
}

int main() {
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> Wi[i] >> Vi[i];
    cout << process(N - 1, W);
}