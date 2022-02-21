#include <bits/stdc++.h>

using namespace std;

int N, C[10005], M[10005], a, b, c;

int process(int idx) {
    if (idx > N)
        return 0;
    if (M[idx])
        return M[idx];
    return M[idx] = max(C[idx] + process(idx + 3), process(idx + 1));
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> C[i];
    if (N <= 3)
        cout << max(max(C[1], C[2]), C[3]);
    else
        cout << process(1);
}